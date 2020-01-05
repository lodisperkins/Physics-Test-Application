
| Lodis Perkins|
| :---          	|
| s188043     	|
| Physics For Games |
| Custom Physics Simulation Documentation |

## I. Requirements

1. Description of Problem

	- **Name**: Custom Physics Simulation

	- **Problem Statement**: 
	Implementation and demonstration of custom physics systems implemented within a real time application

	- **Problem Specifications**: 
     Implementation of static and dynamic rigid body physics that interact
together.Forces applied to physics bodies.Visualisation of physics bodies. Physics simulations run as expected without physical errors.



2. Input Information
- A- moves red ball left
- D - moves red ball right
- W - moves red ball up
- S - moves red ball down
- Space - toggles gravity on/off

3.  Output Information 
- The program shows two balls colliding in a realistic way
- 
   
4. User Interface Information
	-The program displays text to show the user what inputs to use to interact with it.

## II. Design

1. _System Architecture_

| 
|:-----------
Battle Ladder Diagram
| ![User Interface gif](https://i.imgur.com/IxF3B4S.jpg)
| 
Starts at the players turn. The player then has the option to attack or defend. Afterwards its the enemies trun to attack. After both have attacked, a check is made to see if either or did. If so the state changes.
|
|:------------
Game Diagram
|![User Interface gif](https://i.imgur.com/EreoNOQ.jpg)
The game starts in the new game state. After the new game state it transfers to the battle state. If the player decides to go to the shop the game goes to the shop state. If they die the game goes to the continue state. I fthey can and want to continue the game goes back to the battle ladder or shop state, otherwaise it exits.

|
Shop Diagram
|![User Interface gif](https://i.imgur.com/HCuHrJN.jpg)
The shop begins in a welcome state to greet the player. Afterwards the player is given a list of options to choose from. If the player wants to buy an item it first checks if they have enough money. If not, it enters the broke state which either allows the to leave or go back to the main menu. If they can buy it it enters the sellstae and gives the player the option to either leave the shop or go back to the main menu which is in the wait state.
|
1. _User Interface_(This is where each UI element is explained. For example each menu option the player has should would be explained here.)


The program displays buttons and testures for the player to intract with based on the state they are in the game.

### Shop Interface

|![User Interface gif](https://media.giphy.com/media/4NtPkWuzbu3LrLpt24/giphy.gif)

### Battle Interface

|![User Interface gif](https://media.giphy.com/media/1vZ6PefLQIFof0HhzZ/giphy.gif)
 

3. ### Object Information(All classes and their atrributes shsould be described here.)

   **File**: Armor.h(File name or class name)

     Description: Used to boost the characters stats if equipped.(Description of what the class is used for.)
     
    **Attributes(This is a list of each variable,function, and property inside the class**

         Name: name
             Description: Holds the name for the item.
             Type: const char*

        Name: defenseBoost
             Description: Holds the number that adds to the characters defense variable if equipped.
             Type: float

        Name: health_Value
             Description: Holds the number that adds to the characters health variable if equipped.
             Type: float

        Name: strength_Value
             Description: Holds the number that adds to the characters strength variable if equipped.
             Type: float
        Name: Armor
             Description: Constructor that initializes the structs variables
             Visibility: Public

    **File**: Attack.h

     Description: Used to change the characters attack if equipped.
    **Attributes**

         Name: name
             Description: Holds the name for the item.
             Type: const char*

        Name: mDamage
             Description: Holds the number that decrements the enemies health.
             Type: float

        Name: usage
             Description: Holds the number that limits the amount of times a player can use the attack.
             Type: float
     **Operations**:

        Name: Attack
             Description: Constructor that initializes the structs variables
             Visibility: Public
    **File**: Item.h

     Description: Used to in the shop to store items to be bought by the player.
    **Attributes**

         Name: name
             Description: Holds the name for the item.
             Type: const char*

        Name: mCost
             Description: Holds the number that decrements the heroes gold.
             Type: int
     **Operations**:

        Name: Item
             Description: Constructor that initializes the structs variables
             Visibility: Public
    **File**: AttackItem.h

     Description: Used to in the shop to store attacks to be bought by the player.
    **Attributes**

         Name: newattack
             Description: Holds the item to be bought by the player.
             Type: Attack
     **Operations**:

        Name: AttackItem
             Description: Constructor that initializes the structs variables
             Visibility: Public
    **File**: DefenseItem.h

     Description: A defense item stores armor that the hero can equip. Unlike normal armor, defense items have a cost variable that is used to decrement the hero's gold
    **Attributes**

         Name: suit
             Description: Holds the item to be bought by the player.
             Type: Armor
     **Operations**:

        Name: DefenseItem
             Description: Constructor that initializes the structs variables
             Visibility: Public
     **File**: Shop.h

     Description: Stores item that the player cann buy and then equip.

    **Attributes**

         Name: armorstock
             Description: Holds the DefenseItems that the store can sell
             Type: vector<DefenseItem>

        Name: attackstock
             Description: Holds the AttackItems that the store can sell
             Type: vector<AttackItem>

        Name: storestate
             Description: Used to switch states to manage and update the user interface.
             Type: enum

        Name: sellstate
             Description: Used to switch states to draw different animations for the sprite.
             Type: enum
        Name: menustate
            Description: Used to switch between states to update the user interface.
            Type: enum
        Name: idletexture
            Description: Stores the shopkeeps idle texture.
            Type: Texture*
        Name: welcometexture
            Description: Stores the shopkeeps greet texture.
            Type: Texture*
        Name: selltexture
            Description: Stores the shopkeeps selling texture.
            Type: Texture*
        Name: shop
            Description: Stores the shops background texture.
            Type: Texture*
        Name: hero
            Description: Stores the shopkeeps selling texture.
            Type: Texture*
        Name: shopkeep
            Description: This is the texture that is used to draw based on the current state the shop is in.
            Type: Texture*
     **Operations**:

        Name: viewAttacks
             Description: Used to get the name of the attack at the given index.
             Arguments: int
             Type: const char*
             Visibility: Public
        Name: viewArmor
             Description: Used to get the name of the armor at the given index.
             Arguments: int
             Type: const char*
             Visibility: Public
        Name: getstocksize
             Description: Used to get the size of the desired item stock.
             Arguments: int
             Type: int
             Visibility: Public
        Name: affordattack
             Description: Used to determine whether the player can afford an attack.
             Arguments: int,int
             Type: bool
             Visibility: Public
         Name: afforddefense
             Description: Used to determine whether the player can afford a potion.
             Arguments: int,int
             Type: bool
             Visibility: Public
        Name: draw
             Description: Used to draws text and sprites on the screen
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public        
        Name: drawtext
             Description: Used to draw text on the screen
             Arguments: Renderer2D,Font*
             Type: void
             Visibility: Public
        Name: drawsprite
             Description: Used to draw textures on the screen
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public
        Name: destroy
             Description: Used to delete the armorstock,and attackstock.
             Type: void
             Visibility: Public
    **File**: Accuracy.h

     Description: Stores two values used to determine whether a characters attack actually works. 

    **Attributes**

        Name: min
             Description: Holds the minimum value that the player can have in order to land a hit.
             Type: int
        Name: max
             Description: Holds the maximum value that the player can have in order to land a hit.
             Type: int
    **File**: Character.h

     Description: Character is an abstract class that both hero an enemy inherit from. 

    **Attributes**

        Name: name
             Description: Holds the string value that will be the characters chacters name.
             Type: string
        Name: mHealth
             Description: Holds the value that represents the characters health.
             Type: float
        Name: mDefense
             Description: Holds the value that represents the characters defense.
             Type: float
        Name: mStrength
             Description: Holds the value that represents the characters strength.
             Type: float
        Name: mAccuracy
             Description: Holds the value that represents the characters accuracy.
             Type: Accuracy
        Name: listofattacks
             Description: Holds the characters current attack options.
             Type: Attack
    **Operations**:
    
        Name: takeDamage
             Description: Used to decrement the characters health.
             Arguments: float
             Type: virtual void
             Visibility: Public
        Name: getHealth
             Description: Returns the characters health.
             Type: float
             Visibility: Public
        Name: fight
             Description: Decrements the opponents health based on the attack value at the index given.
             Type: Character&,int
             Visibility: Public
    **File**: Hero.h

     Description: Character is an abstract class that both hero an enemy inherit from. 

    **Attributes**

        Name: mGold
             Description: The total amount of money the hero has.
             Type: int
        Name: mArmor
             Description: The current armor the player has equiped.
             Type: Armor
        Name: armorBag
             Description: Holds the total amount of armor the player has bought.
             Type: vector<Armor>
        Name: attackBag
             Description: Holds the total amount of attack the player has bought.
             Type: vector<Attack>
        Name: current
            Description: Used to switch the state of the player to update the options in the user interface
            Type:enum
        Name: hero
            Description: Stores the texture for the player
            Type:Texture*
        Name: corruptedhero
            Description: Stores the texture for the players character once they play the game for a second time
            Type:Texture*
    **Operations**:
    
        Name: draw
             Description: Used to draw text and sprites to the screen.
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public
        Name: drawtext
             Description: Used to draw text to the screen.
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public
        Name: drawsprite
             Description: Used to draw sprites to the screen.
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public
        Name: revive
             Description: If the player has died, this function is used to decrement their gold by 500 and allow them to play again.
             Type: void
             Visibility: Public
        Name: reward
             Description: If the player has won a battle, this function is used to add to their gold by 500 and allow them to play again.
             Type: void
             Visibility: Public
     **File**: Game.h

     Description: Draw and displays button options based on the current state of the game. 

    **Attributes**

        Name: item_Shop
             Description: Creates a shop for the player to interact with.
             Type: Shop
        Name: player
             Description: Creates a hero for the player to control.
             Type: Hero
        Name: currentEnemyPtr
             Description: Creates an iterator to iterate through the enemy linked list
             Type: iterator<Enemy>
        Name: Start
             Description: Creates a variable of type newgame that is used to call fucntions only needed when starting a new game
             Type: newGameClass   
        Name: between
             Description: Creates a variable of type ncontinue that is used to call functions only needed when asking the player of they want tom continue the game.
             Type: Continue 
        Name: pchoice
             Description: Creates a variable used to access the listofattacks array based on  the player choice of an attack they would like to use.
             Type: int
        Name: echoice
             Description: Creates a variable used to access the listofattacks array based on a randomly generated number.
             Type: int
        Name: current
             Description: Creates a variable used in a switch todetermine the current gamestate the game is in.
             Type: enum
    **Operations**:
    
        Name: draw
             Description: Used to draw text and sprites to the screen.
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public
        Name: gameEnd
             Description: Asks the player if they want to play again, if not returns false.
             Type: void
             Visibility: Public
        Name: draw
             Description: Used to draw text and sprites to the screen.
             Arguments: Renderer2D,int,Font*
             Type: void
             Visibility: Public
        Name: initializeladder
             Description: Creates a new linked list and assigns the enemies their attack and stats.
             Type: void
             Visibility: Public
        Name: initializenewladder
             Description: Creates a new linked list and assigns the enemies their attack and stats. Also adds the players previous character to the list of enemies.
             Arguments: Hero*
             Type: void
             Visibility: Public
        Name: battleladder
             Description: Pits the player against a list of enemies that allows them to traverse the list as they complete battles.
             Arguments: Hero*&
             Type: void
             Visibility: Public
        Name: Continue
             Description: Gives the player the option to continue.
             Type: void
             Visibility: Public
        Name: Shop
             Description: Updates the user interface to display the shop and its options.
             Arguments: Hero*
             Type: void
             Visibility: Public
        Name: Shop
             Description: Creates the shops items and puts it in the armror and attack stocks.
             Type: void
             Visibility: Public
    **File**: list.h

     Description: Draw and displays button options based on the current state of the game. 

    **Attributes**

        Name: count
             Description: Keeps track of the size of the list.
             Type: int
        Name: first
             Description: Creates a pointer to the first index of the linked list.
             Type: int
        Name: last
             Description: Creates a pointer to the last index of the linked list.
             Type: int
     **Operations**:
    
       Name: operator=
             Description: Overloads the operator to have it call the copy function instead
             Arguments: const list<h>
             Type: const list<h>
       Name: initialize
             Description: Creates a linked list and sets its first and last to null pointers.
             Type: void
        Name: isEmpty
             Description: Returns true if the lists count is set to zero.
             Type: const bool
        Name: print
             Description: Prints the elements of the linked list to the console
             Type: const void
        Name: length
             Description: Returns the linked lists count.
             Type: const int
        Name: destroy
             Description: Deletes all elements inside the linked list
             Type: void
        Name: front
             Description: Returns the linked lists first item.
             Type: const h
         Name: back
             Description: Returns the linked lists last item.
             Type: const h
        Name: search
             Description: Iterates through the list until it finds the desired result and then reutrns true.
             Arguments: const list<h>
             Type: virtual bool
        Name: insertfirst
             Description: Adds a node to the front of the list
             Arguments: const h
             Type: virtual void
        Name: insertfirst
             Description: Adds a node to the last of the list
             Arguments: const h
             Type: virtual void
        Name: deleteNode
             Description: Searches for the desired nodes data and then removes that node.
             Arguments: const h
             Type: virtual void
        Name: begin
             Description: Returns an iterator pointing to the beginning of the list
             Type: iterator<h>
        Name: end
             Description: Returns an iterator pointing to the end of the list
             Type: iterator<h>
        Name: copylist
             Description: Copys a list on to a new one and deletes the old list
             Type: void
    **File**: nodetype.h

     Description: Creates individual nodes that make up a linked list

    **Attributes**

        Name: info
             Description: Stores the nodes data
             Type: templated type
        Name: link
             Description: Stores the nodes data
             Type: templated type
    **File**: iterator.h

     Description: Creates a pointer to the linked lists that is capable of navigating through it.

    **Attributes**

        Name: current
             Description: Points to a desired area in the linked list.
             Type: nodetype<templated typename>*
    **Operations**:
    
       Name: GetNext
             Description: Returns the next item in the linked list.
             Type: nodetype<templated typename>
        Name: operator *
             Description: Returns what the iterators current is pointing to.
             Type: templated typename
        Name: operator++
             Description: Makes the iterator go to the next spot in the linked list
             Type: iterator<templated typename>
        Name: operator ==
             Description: Returns true if an iterators current is the same as the current in this instance.
             Type: const bool
        Name: operator ==
             Description: Returns true if an iterators current is not the same as the current in this instance.
             Type: const bool
