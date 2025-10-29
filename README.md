# Lucky Cat Casino, by Mathew Neves & Jacob Pancoast

This program is a simple simulation of a few popular casino games, European roulette, slots and blackjack, and also includes war as a time waster. It uses a dedicated Roulette.h and class, a
dedicated Slots.h and class, a Casino.h and class, a Blackjack.h and class, and an abstract Game.h, and attempts to build a robust program that is difficult 
to break and will run without issue. We have implemented some larger methods, mostly because we want the program to run WITHOUT needing more than a few lines of code 
in the main.cpp file. This is so that this code can be implemented more easily along with other classes. 

For this first release version, we revamped our multiple instances of file IO being used to track a player's chip balance. The login uses files named after a user's chosen username, and 
reads/writes a line for that player's balance using methods in the Casino class. There is now also true statistics tracking for each user, beyond just tracking the amount of chips they have. 
It includes their games played for each one of our games, as well as their wins and losses. This stat tracking has live updates and also uses matplotlib in Python so users 
can see graphs of their income over time. The program still starts in C++, but uses the other inclusions for the graphing and stats portion of the project. Python was the 
best use for the graphing, primarily because we already have used matplotlib and it is quite a simple and repeatable system. JSON, while not a language, was a logical switch for the user_cache files 
because it makes editing values through C++ much more simple. C++ is used to call Python and does so in the GetStats() method of the Casino() class. It uses a system line to call the .py 
file through CLI. 

There is also a new game, war, which is made to be a fun time waster and to test new concepts and skills. It is made to be implemented efficiently yet competently and was included 
to improve the overall user experience.

# Update Log
* Pre-release 0.0.1: Added Roulette and Slots, created Casino class
* Pre-release 0.0.2: Added Blackjack and User Profile saving, modified class relationships
* Early Access 0.1.0: Added War, revamped User Profile system, added statistics tracking

# How To Run

You should be able to run just by cloning the repository and using the included LuckyCatCasino.exe, but if that does not work, follow the steps below:

We have only compiled in Windows, and have done it with the steps below. If you must compile elsewhere, ignore the test.cpp file and any other compilers (in this case CMake)
You should use G++ to compile this program. In Windows Powershell, compile with the following:

```
g++ (Get-ChildItem -Recurse -Filter *.cpp | Where-Object { $_.Name -notin @("test.cpp", "CMakeCXXCompilerId.cpp") } | ForEach-Object { $_.FullName }) -I. -IGames -ICasino -o LuckyCatCasino.exe
```

And run the LuckyCatCasino.exe with:

``` 
.\LuckyCatCasino.exe
```

# Known Bugs

In some VERY rare cases, you can overwhelm the program with your inputs. This only happens if a user is spamming inputs when not prompted. 
There is not really much of an easy fix for this, since it is an extreme case, and it will cause some funky backlogging stuff to happen. I do, 
however, think that the program eventually fixes itself once valid inputs are given.

IF ANY BUGS ARE FOUND, PLEASE EMAIL ONE OF THE CREATORS:  
https://github.com/matcat7  
https://github.com/jacob-pancoast17  


# Future Plans

Currently, We have plans to implement this program as a part of a much larger casino project that would contain many
popular games, poker, horse racing, and more! In this class, there is already framework to set up a wheel for 
this game, which We plan to expand with a broader "wheel" class, because games such as roulette
or spin to win are a wheel, and could use a basic framework. We have also set up the code to add some secrets
and user-friendly elements. There will also eventually be statistics files.
  
We also wanted to expand the roulette game more, especially since players should also be able to bet on a range of numbers
or bet even/odd. This would have been a massive implementation, but also would likely require more rules. When the casino
class eventually has a rulebook area, We will likely implement these more complex game elements.

# Citations

The timer concept used was modified from: https://www.geeksforgeeks.org/cpp/how-to-make-a-countdown-timer-in-cpp/  
Information on roulette was found on: https://www.partycasino.com/en/blog/how-to-play-roulette/  
ASCII art font: https://patorjk.com/software/taag/#p=display&f=Big&t=Lucky+Cat+Casino&x=none&v=4&h=4&w=80&we=false  
ASCII art cat: https://www.asciiart.eu/animals/cats  

# Other Notes

A list of future additions that will be made to this program:
* Input validation simplified to a helper function instead of nested loops
* More games, including poker, and other popular casino activities
* Graphics, including simple game simulations
* Player cosmetics, purchasable with chips (these would not reset upon hitting zero)
* More secrets and Easter eggs!
  
We just wanted to make something fun this semester, so have fun yourself!
