-- FIFTYVILLE: https://cs50.harvard.edu/x/2023/psets/7/fiftyville/

-- Keep a log of any SQL queries you execute as you solve the mystery.

-- FIND CRIME SCENE DESCRIPTIONS:

SELECT description
FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2021
AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- each of their interview transcripts mentions the bakery.
-- Littering took place at 16:36. No known witnesses.

-- GETTING TRANSCRIPTS FROM CRIME DAY:

SELECT transcript FROM interviews
WHERE day = 28
AND month = 7
AND year = 2021
AND transcript LIKE '%bakery%';

-- FIRST TRANSCRIPTION:
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

-- SECOND TRANSCRIPTION:
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

-- THIRD TRANSCRIPTION:
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- FROM THE FIRST TRANSCRIPT:

SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE day = 28
AND month = 7
AND year = 2021
AND hour = 10
AND minute >= 15 AND minute <= 25
AND activity = "exit";

-- SUSPECTS NAMES:

-- Vanessa
-- Bruce
-- Barry
-- Luca
-- Sofia
-- Iman
-- Diana
-- Kelsey

-- FROM THE SECOND TRANSCRIPT:

SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE day = 28
AND month = 7
AND year = 2021
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- SUSPECTS NAMES:

-- Bruce
-- Diana
-- Iman
-- Luca

-- FROM THE THIRD TRANSCRIPT:

SELECT name FROM people
JOIN passengers ON passengers.passport_number
= people.passport_number
WHERE passengers.flight_id = (
    SELECT id FROM flights
    WHERE day = 29
    AND month = 7
    AND year = 2021
    AND origin_airport_id = (
        SELECT id FROM airports
        WHERE city = 'Fiftyville')
        ORDER by hour, minute
        LIMIT 1);

-- SUSPECTS NAMES:

-- Bruce
-- Luca

SELECT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE day = 28
AND month = 7
AND year = 2021
AND duration < 60;

-- THIEF:

-- Bruce

-- CITY THE THIEF ESCAPED TO:

SELECT city FROM airports
WHERE id = (
    SELECT destination_airport_id FROM flights
    WHERE day = 29
    AND month = 7
    AND year = 2021
    AND origin_airport_id = (
        SELECT id FROM airports WHERE city = 'Fiftyville')
        ORDER by hour, minute
        LIMIT 1);

-- New York City

-- FINDING WHO THE THIEF'S ACCOMPLICE:

SELECT phone_number FROM people WHERE name = "Bruce";

-- (367) 555-5533

SELECT name FROM people WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller = '(367) 555-5533');

-- Robin
