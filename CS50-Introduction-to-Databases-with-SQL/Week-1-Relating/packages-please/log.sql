
-- *** The Lost Letter ***
-- First I checked if Anneka really sent the package.
-- After trying to find the package, I noticed that I couldn’t find it in the database.
-- Than I tried to check if the address was misspelled since she mentioned that the name
-- was a bit tricky, and there we go. I found out that the address was misspelled
-- and got the id of it using the following query:
SELECT address, id FROM addresses WHERE address LIKE "%Fin%";

-- After that I checked if the content of the package really matched what Anneka was saying,
-- for that I used the following query:
SELECT contents FROM packages WHERE to_address_id = 854;

-- To check the type of address where the package was sent I used the following query:
SELECT address, type FROM addresses WHERE address = "2 Finnigan Street";



-- *** The Devious Delivery ***
-- First I used the hint that the package had no sent address,
-- so I assumed that from_address from addresses would be NULL,
-- and I collected all the information I could with the following query:
SELECT id, contents, from_address_id, to_address_id WHERE from_address_id IS NULL;

-- With the information collected I used the package id
-- and searched through scans table to find if the package
-- was really picked and delivered, and if delivered, where it was received:
SELECT package_id, address_id, action FROM scans WHERE package_id = 5098;

-- Finally I searched to find where the package was really delivered:
SELECT address, type FROM address WHERE id = 348;



-- *** The Forgotten Gift ***
--  First I got the addresses ids from where it was sent and from where it should be delivered:
SELECT id FROM addresses WHERE address IN ("728 Maple Place", "109 Tileston Street");

-- Then I checked the content of the package and its id:
SELECT id, contents FROM packages WHERE from_address_id = 9873 AND to_address_id = 4983;

-- With the package id I checked the scans table to find the driver's id and the state of the deliver.
-- If it wasn't delivered yet it means it was with the driver.
SELECT driver_id, address_id, action FROM scans WHERE package_id = 9523;

-- Finally I searched through the drivers table to find the name of the driver
SELECT name FROM drivers WHERE id = 17;
