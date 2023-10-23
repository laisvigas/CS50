# Hall of Prophecy : https://cs50.harvard.edu/x/2023/problems/7/prophecy/

import csv
from cs50 import SQL

def create_house(house, houses, head):
    sum = 0
    for c in houses:
        if c["house"] == house:
            sum += 1
        if sum == 0:
            houses.append({"house": house, "head": head})


def create_students(name, students):
    students.append({"student_name": name})


def create_assigments(name, house, assigments):
    assigments.append({"student_id": name, "house_id": house})

db = SQL("sqlite:///roster.db")

students = []
houses = []
assigments = []

with open('students.csv', 'r') as csvfile:
    file = csv.DictReader(csvfile)
    for row in file:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        create_house(house, houses, head)
        create_students(name, students)
        create_assigments(name, house, assigments)

for student in students:
    db.execute("INSERT INTO HogwartStudents (student_name) VALUES (?)", student["student_name"])

for h in houses:
    db.execute("INSERT INTO houses (house, head) VALUES (?,?)", h["house"], h["head"])

for assigment in assigments:
    db.execute("INSERT INTO assigments (student_id, house_id) VALUES (?,?)", assigment["student_id"], assigment["house_id"])
