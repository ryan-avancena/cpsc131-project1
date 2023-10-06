## Project-1---Vectors

Name: Ryan Avancena
CWID: 885367821


# Inventory 
Inventory - Inventory function will take care of all the operations. Inventory class will have one vector which will store objects of Item. 
Add New Item: Write a function addNewItem() which will add a new Item in your vector. While adding a new element in the vector, check whether it already exists in the vector or not. If it exists in a vector, then display the message as “Item is already present in inventory”. 
Increase Quantity: Write a function increaseQuantity() to increase the quantity of the item by the newly provided quantity. It will take two parameters: itemname and quantity. 
Update Item: Write a function updateItem() which will update the quantity, expiration and category. updateItem() will take four parameters: itemname, expiration, quantity and category. It should search the item from the name and update the item with given parameters. We can only update the items that are already present in inventory. If time is not found throw an exception “Item not found”.
Remove Item : Write a function removeItem() which will remove a particular item from the vector on the name of item. The function removeItem() takes a parameter as itemname. If an item is not in an inventory and you are trying to remove it from inventory, it will throw an exception “Item not found”.  
Total: Write a function Total() to calculate the total number of items in inventory. 
Search Item: Write a function searchItem() to search a particular item in the inventory. The function searchItem() takes a parameter itemname and based on that it will find an item. If an item is not present it will throw an exception “Item not found!!”.

# Appointment System
Schedule: Write a function schedule() to schedule an appointment. It will store an appointment in a vector. If CWID is already present in a vector, then display the message that “You have already scheduled an appointment!!!”. It will store an object in a vector. 
Total_appointments: Write a function Total_appointments() to calculate a total number appointments on a particular date and at a particular time. It will take two parameters: date and time. 
Remove recent:  Write a function removeRecent() to delete an appointment that is recently booked. 
