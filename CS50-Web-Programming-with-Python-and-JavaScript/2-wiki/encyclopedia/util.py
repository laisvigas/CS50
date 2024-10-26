import re

from django.core.files.base import ContentFile
from django.core.files.storage import default_storage


def list_entries():
    """
    Returns a list of all names of encyclopedia entries.
    """
    _, filenames = default_storage.listdir("entries")
    return list(sorted(re.sub(r"\.md$", "", filename)
                for filename in filenames if filename.endswith(".md")))


def save_entry(title, content):
    """
    Saves an encyclopedia entry, given its title and Markdown
    content. If an existing entry with the same title already exists,
    it is replaced.
    """
    filename = f"entries/{title}.md"
    if default_storage.exists(filename):
        default_storage.delete(filename)
    default_storage.save(filename, ContentFile(content))


def get_entry(title):
    """
    Retrieves an encyclopedia entry by its title. If no such
    entry exists, the function returns None.
    """
    try:
        f = default_storage.open(f"entries/{title}.md")
        return f.read().decode("utf-8")
    except FileNotFoundError:
        return None


def markdown_to_html(markdown):
    # Convert headings
    markdown = re.sub(r'^(#{1,6})\s*(.*)', lambda m: f'<h{len(m.group(1))}>{m.group(2)}</h{len(m.group(1))}>', markdown, flags=re.MULTILINE)
    
    # Convert bold text
    markdown = re.sub(r'\*\*(.*?)\*\*', r'<strong>\1</strong>', markdown)

    # Convert unordered lists
    markdown = re.sub(r'^\*\s*(.*)', r'<ul>\n<li>\1</li>\n</ul>', markdown, flags=re.MULTILINE)

    # Convert links
    markdown = re.sub(r'\[(.*?)\]\((.*?)\)', r'<a href="\2">\1</a>', markdown)

    # Convert paragraphs (any text not wrapped in tags will be in a paragraph)
    def wrap_paragraphs(text):
        paragraphs = text.split('\n\n')
        wrapped_paragraphs = []
        for paragraph in paragraphs:
            if not paragraph.strip().startswith('<'):
                wrapped_paragraphs.append(f'<p>{paragraph.strip()}</p>')
            else:
                wrapped_paragraphs.append(paragraph)
        return '\n\n'.join(wrapped_paragraphs)

    markdown = wrap_paragraphs(markdown)
    return markdown
