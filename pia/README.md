# Final Project (PIA) :  Shopping Cart 
Store that will use the program: "The Fastest & Coolest - Market" 


>The objective of this program is to be able to create and innovate an old system of small conventional stores (such as the typical small store on a street corner and other examples of entrepreneurs who start with their small store).
So, it is a fact that innovation for these businesses is fundamental and essential, due to the fact of being at the technological forefront and to eliminate that “manual labor” of type the products for the store cashier.
>
>Link to the project [here](https://github.com/montserrat1318/C/tree/main/pia).


## Table of Contents of the Project
* [Project Plan](#Project-Plan)
* [Autoevaluation](#Autoevaluation)
* [Demostration Of The Final Project](#Demostration-Of-The-Final-Project)
* [Cases Applied in my Demo](#Cases-Applied-in-my-Demo)
* [Instructions to Compile the Program](#Instructions-to-Compile-the-Program)
* [References](#References)
* [Contact](#Contact)
<!-- * [License](#license) -->

## Project Plan
The tasks or facilities of my project will be:
* **Product Categorization:** The program is designed so that the store indicates to the programmer the products it sells with their respective prices and finally also indicates the category of each product. For the programmer to place them in such a way in the code.
-In this case, the store for which this program was designed indicated the products and the categories in which they sell it (aunt) -

   Example (Category: Fast Food -> Pizza (4 people), etc ...).
* **Shopping Cart in order:** The program can generate in an orderly manner the categories (in each category its products together with the prices), all in order to visually see all the items in the store in order.
All with the purpose of watch at the end of the program (almost to confirm the order) the articles selected and the quantity.
Also, it is important to mention that in the selection process of the order      **the program sends a notice to ask how many articles will be taken of a certain product (when the user select the product)**, after that question and respective answer, **the program notifies or confirms to the user again when the article (s) is added along with the quantity that was ordered.**

* **Option to delete products:** The program has the option of giving the user the possibility of eliminating certain products from the shopping cart that they previously selected. The user will have the freedom to decide whether or not to delete.
**-->If the user chooses not to delete ... then the program ends and their final ticket will be generated.**
**--> If the user chooses to delete ... then the program will throw up the selection menu to delete the necessary products. And then finally, the final ticket of the updated purchase will be generated.**

* **Promotions / Discount Codes:** The program is designed to automatically apply various promotions or discount codes (depending on the conditions that each promotion or code implies). For this function the library time.h and math.h were used; Since the discount codes are managed after a certain total purchase amount ($) or for certain days of the week where certain categories of products are discounted.
**--PROMOS (Established in the Program):**
**-> Promotion:** From the 1000 pesos in purchase a discount of 15% is made (Just can be applied when there is not other promo of the Day in the categories of products selected).
**-> ProMONDAY:** 13% discount on all items in the "Sodas" category, every Monday at all hours. 
**-> ProTuesday & Wednesday:** 15% discount on all items in the "Fruits and Vegetables" category, every Tuesday and Wednesday at all hours. 
**-> ProThursday:** 20% discount on all items in the "Basic Basket" category, every Thursday at all hours. 
**-> ProFriyay:** 18% discount on all items in the "Fast Food" category, every Friday at all hours. 
**-> ProSatSunyay:** 10% discount on all items in the category "Fast Food", "Sodas", and "Sweets", every Saturday and Sunday every hour. 

* **IVA:** The program is designed to add 16% IVA to absolutely every purchase made without exception.

* **Generate Ticket:** The program has the ability or facility to generate a ticket automatically through a Ticket.txt, which is automatically updated at the time of generating purchase after purchase.

**-> The ticket contains the name of the store, the products with the quantity purchased by the customer with the total purchase price; And it also includes the specification of the promotions or discount codes that were applied automatically in the purchase, the added IVA and with all that information, finally, the total price to pay also appears.**

## Autoevaluation
This project became a total challenge for me, I tried to implement everything I learned and also to be able to investigate with more functions to make my code more complex but optimal in its structure, I know that I should continue working but I consider that I did an excellent job in this draft.
The self-evaluation that I give myself is the following:

-Complexity: **3 points** I think it is a job full of acquired knowledge and even knowledge that I acquired in the process, I implemented things that I had never put to improve cleaning and others. I consider that it is a topic and a necessary program in daily life, and where it implies difficulty to automatically program the .txt and discount codes (for days of the week in certain categories of articles), and that is why I give myself that amount.

-Functionality: **3 points**. Speaking of functionality, I consider that the code perfectly does everything that was planned and in a fast way at the time of execution, it is also completely easy for the user (anyone could execute it and that was the purpose).

-Code: **3 points** I consider that it is very optimized and that it implements new functions that I learned when doing this code and I like that, I did not want to stay with what I could grasp before, but I tried to investigate more to obtain best results.

-Storage: **2 points**. I think it has good storage usage (but I think it can be improved).

-Documentation: **3 points**. I consider that there are all the points that need to be known and I specify the details of the cases of the demonstration (youtube); I did it in an orderly and clean way; also check with time and detail my grammar and writing.

**I think I can have 14/15 points. I'll keep working to improve, thank you very much!**

## Demostration Of The Final Project
-->To access to the demo (YouTube video) of the previously described program, **click on the link below:**

>Link to the demo [here](https://www.youtube.com/watch?v=YHb7lh6JThk).

-->**Check the following section ("Cases Applied in my Demo") to know** in a detailed and written way **the cases made in the demo of the program.**

## Cases Applied in my Demo
* **CASE 1:** In the shopping cart add 10 tomatoes and 5 avocados (purchase less than 1,000 pesos) (without eliminating products). **Objective  to demonstrate:** Demonstrate that the promotion of the day will be applied automatically (in the demonstration "ProTuesday & Wednesday" is applied it)

* **CASE 2:** In the shopping cart add 20 tomatoes and 15 apples (purchase less than 1,000 pesos) (remove products). Before finishing the final purchase, remove 5 apples. **Objective to demonstrate:** Show that the promotion of the day will be applied automatically (in the demonstration "ProTuesday & Wednesday" is applied for the day it was recorded (Wednesday)); and also see that the process of eliminating certain products does not affect anything. 

* **CASE 3:** In the shopping cart add 10 tomatoes, 5 avocados, 3 duvalines and 2 waters (purchase less than 1,000 pesos) (without eliminating products). **Objective to demonstrate:** Show that the promotion of the day will be applied automatically (in the demonstration "ProTuesday & Wednesday" is applied for the day it was recorded (Wednesday)); **Taking into account that products of categories that do not enter the promotion were added (it does not affect the corresponding promotion to be applied to the account).**


* **CASE 4:** In the shopping cart add 1 coca-cola, 1 pizza (4 people), 15 ACE detergent, 2 Olive Oil and 1 Roll Paper (purchase over 1,000 pesos) (without eliminating products). **Objective to demonstrate:** Demonstrate that the advance promotion of 1,000 pesos will be applied automatically (15% discount). *And being Wednesday, the promotion of the day will not be applied because there are no products in the "Fruits and Vegetables" category.*

* **CASE 5:** In the shopping cart add 1 coca-cola, 1 pizza (4 people), 15 ACE detergent, 2 Olive Oil and 1 Roll Paper (purchase over 1,000 pesos) (remove products), and before completing the total purchase; remove 1 Pizza (4 people). **Objective to demonstrate:** Demonstrate that the advance promotion of 1,000 pesos will be applied automatically (15% discount). And that **removing a product from the shopping cart does not affect anything.** *And being Wednesday, the promotion of the day will not be applied because there are no products in the "Fruits and Vegetables" category.*

* **CASE 6:** In the shopping cart add 10 coca-cola, 3 duvalines, 1 paper roll, and then add 1 coca-cola again (purchase less than 1,000 pesos) (eliminate products), and before complete the total purchase; remove 1 duvalin. **Objective to demonstrate:** Show that the correct amount of coca-cola will be applied to the ticket, despite adding amounts of the same product at different times.

## Instructions to Compile the Program
-->To compile correctly the program, follow the next instructions:

1.- Open Dev C++ or OnlineGDB Compiler **(It´s better if you used Dev C++, to have a better experience with the cleanliness of the program in the moment of run it) (But online compiler works too, of course.)**

2.- Open or put the file *"shoppingcart.c"* (founded in carpet: pia->code files->shoppingcart.c) on the compiler

3.- Create another file in that same project (compiler project), in which you will put the header *"menus.h"* (founded in carpet: pia->code files->menus.h)

4.- Execute the program as you wish and in the final step of the program *("End of the shopping cart actual order")*, you will notice that...

5.- It will appear a file called *"Ticket.txt"; that .txt appears **AUTOMATICALLY** at the end of every *("End of the shopping cart actual order")*

**NOTE ABOUT THE TICKET.txt:** The ticket.txt file, it is automatically updated at the end of each purchase made by the user (please give "refresh" every time the program asks if you want to update your ticket).

**TIP FOR THE FILE TICKET.txt:** The ticket.txt file, **it is best viewed from a .txt file (aligned)** (not from dev c ++, as it looks a bit misaligned from the console) **or from the online** (it looks perfectly aligned)


## References
-->For this project or the shopping cart program, I use certain fundamental references to carry out functions, libraries, etc... of the code, which are the following:

1.- Kernighan, B. W., & Ritchie, D. M. (1973). The C Programming Language (2.a ed.) [Electronic Book]. Prentice Hall. 

2.- Silverman, J. H. (2007, 15 Jan). The C Reference Card (ANSI). CRefCardVolume2.  

3.- Cómo calcular qué día de la semana fue. (2016, 28 Jan). Gaussianos.[here](https://www.gaussianos.com/como-calcular-que-dia-de-la-semana-fue/). 

4.- Converting to Numbers (NUMVAL, NUMVAL-C). (s. f.). Valnum. Recovered 11 de may de 2021 [here](https://www.ibm.com/docs/en/i/7.2?topic=functions-converting-numbers-numval-numval-c).

## Contact
You can contact me in:
-->Discord as  **montserrat_orozco_13#6074** 
-->In **my profile of GitHub:** [here](https://github.com/montserrat1318) 
-->In **my personal YouTube Channel** [here](https://www.youtube.com/channel/UCMV5nUXAt0J-El-bIdc1S-g).
