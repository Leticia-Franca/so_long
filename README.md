# so_long  
![so-long-gif](https://github.com/Leticia-Franca/so_long/blob/main/img_files/so_long3.gif)

This is the project where you get in touch with the *graphic library*. Yey!  
Basically, So_Long is about you creating your first 2D game. It's supposed to be simple, though, so don't get worked up 😁 (besides, you'll have lots of chances to go crazy making games in the future, if that's what you want haha).  
The idea is really straightforward:  
- You'll display a map with some collectables and a character on the screen  
- The character must collect all the items before leaving the map  
  
If you're new to this (as I was), you may ask: Okay, I know how to deal with I/O and to write functions at this point, but how will I deal with graphic elements?  
So here it is the awaited, the one, the only...    

## The MiniLibx (or: *getting to know the graphic library*)  

But what exactly is in between the connection with the graphic server and the function that'll loop through the program over and over to keep and update the game?  
What is in this sandwich?  
## The Part You Play (or: *your code in the loop and.. the graphic elements per se*)  
**pun not intended.. or is it?**  
Okay, we knew this. But I wanted to point out. You'll incorporate the MiniLibx (which is the big news here), and aside from that, you'll put to use *in a new bright light* what you already know and came to (maybe?) appreciate:  
 - Parsing  
 - Storing
 - Validating  
Let's take a step back.  
1. Your program will receive a document .ber as an argument.  
2. This document will serve as a frame (a skeleton) for the images you'll put on the window.  
3. You have to find a way for your program to:
    - Keep its content, so your program can access it when needed;  
    - Validate this content in accordance with the project's rules;  
    - Manipulate this content whenever some event happens (a.k.a the user interacts with the game);  
4. And you'll display your game based on this content (I'm basically reinforcing point 2 here) *over and over*.  
