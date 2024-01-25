Cs50 Cybersecurity Assignment 1

https://cs50.harvard.edu/cybersecurity/2023/assignments/1/

#### Grade: 7/10

## 1. Characterize the difference between a database hack and a database leak. [1/1]
Database leak is when sensitive information is leaked without necessarily he awareness of the public, while in database hack someone or some group of people intentionally attack a system to get access to the data in there.
 
## 2. In what sense might files not actually be deleted even if you empty the recycle bin on Windows or empty the trash on macOS? [0/1]
The computer takes the “deleted” files out of our sight and free that space in a sense that a new file can overwrite the information that is there. If that information has not been overwritten yet, those files might still be recovered.
 
## 3. How do quantum computers differ from traditional (non-quantum) computers? [1/1]
The idea of bits is implemented differently in quantum computing. There’s this idea of quantum bit or qubit whose power drives from the reality that we can physically implement a qubit in such a way that it is representing both 0 and 1 at the exact same time. 
 
## 4. What is the term for the prevailing method via which public-key (i.e., asymmetric) cryptography enables two parties to establish a shared secret, even over an insecure (i.e., unencrypted) channel? [0/1]
Asymmetric-Key Encryption
 
## 5. What is a salt, in the context of this lecture? [1/1]
Salt, in the context of this lecture is the process of modifying the hash function to take two inputs, not just the password, but also another generated characters that are not meant to be private or secure, but are meant to make sure that whatever hash value is generated, it will be a little bit different if another hash value were added. This way is less likely that two identical passwords generates the same hash value.
 
## 6. Suppose that Alice and Bob need to coordinate a meeting, as by exchanging emails using Microsoft Outlook, a popular client for email. If their emails are encrypted in-transit, who (besides Alice and Bob) might nonetheless be able to read the emails if anyone, and why? [1/1]
Any employee working on Outlook’s server could technically be reading the messages because the messages sent from Bob to Alice and vice-versa are encrypted only when sent to Outlook, in other therms, while in-transit. In this case Alice has a secure connection to Outlook and Bob has a secure connection to Outlook, but that doesn’t mean, necessarily, that Alice has a security connection to Bob. The data is only encrypted while in transit from Alice to Outlook and from Bob to Outlook.
 
## 7. Suppose that you have been hired to perform some work for Charlie. After agreeing to terms, you send the contract to Charlie via email, and, later that day, you receive a digitally signed copy from an email address that appears to belong to Charlie but isn't the one to which you sent the contract originally. How can you be as certain as possible, technologically (that is, without consulting Charlie) that Charlie was the one who digitally signed the contract? [1/1]
I can take Charlie’s public key, take the signature and decrypt his signature with his public key, so, if I get the exact same hash after decrypting what Charlie sent me, it proves that he was the one that really signed the document.
 
## 8. MD5 is an example of a still popular hashing algorithm that has been in use since the early 1990s. Read this article about MD5 before continuing on. Note that MD5 is a 128-bit algorithm, meaning its digests (i.e. hash values) are always 128 bits in length, and therefore there are 2^128 unique digests available. Thus, understand that the article's critique that there is a "high potential for collisions," while not invalid or indeed even incorrect, is perhaps something that should be understood with a bit of context. Suppose that a company has made a large file available for download via its website. Why might they also make available the MD5 hash of that file (as is indeed a common practice)? [1/1]
Because it would be possible to verify the integrity of the file with the MD5 hash of that file, making the verifying process more efficient.
 
## 9. Identify one or more significant differences between a cipher and a hash. [1/1]
Cipher, or encryption, is reversible, while hashing generally is not.
 
## 10. Otkz D zvmizy v amzz kjdio! di ocz wjs wzgjr. No, the above isn't random typing! :) [0/1]
Type E earned a free point! in the box below.