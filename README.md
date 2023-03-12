  > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# MovieRec
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Nathanael Shin(nshin014)](https:://github.com/nks738)\>, \<[Henry Zheng(hzhen055)](https://github.com/HenryKZheng)\>, \<[John-Paul Sassine(jsass003)](https://github.com/jpsassine)\>
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > * Purpose <br />
 > Our project is called MovieRec. This program will allow users to input a movie and upon receiving it, our program will run through 
 a list of different movies and recommend three movies they might like based on the information they gave the program. To accomplish this, we would 
 navigate through a list of movies and compare the genre and rating of the chosen movie with the movies in the list. The final output will be 3 movies that 
 most closely match with the user's movie. 
 
 > * Why we Chose MovieRec <br />
 We decided to do this project because our group really enjoys watching different movies and thought it would be a neat idea to have a program that would
 recommend different movies when we run out of things to watch.
 > * Tools <br />
 [Movie List](https://data.world/owentemple/greatest-films-of-all-time/workspace/file?filename=guardian_2010_greatest_films_of_all_time.csv) - list of movies to compare with users movie <br />
 [C++] - language <br />
 
 > * Input and Output <br />
 Input: Movie, Genre, Date, Actor, Rating <br />
 Output: Recommended movies based off input <br />
 
 > * Design Patterns <br />
Composite Design Pattern: <br />
Since the Composite design pattern revolves around a style of designing that incoporates a group of objects that would be treated as instances of the same object, we believe we could use this pattern when dealing with subcategories within categories(such as different categories under seasonal categories). For example, when comparing movies, the user could input a subcategory like rom-com in the comedy genre to narrow down the search even more. <br />

> * Strategy Design Pattern: <br />
Due to the fact that our project has various features that require different algorithms to organize and present the movies, we will use the strategy design pattern to give us the ability to switch through algorithms as we see fit and give us more control over the various features. This way we can organize our different “sorts” (sort by alphabetical order, sort by best rated, etc.). <br />

> * Factory Design Patter: <br />
This design pattern will aid us in the creation of the initial objects, as these movie objects will have many sub classes that they can be categorized into (i.e genre, season, length). One piece of functionality that we will incorporate using the abstract factory pattern is the direct conversion of data into objects using classes of movies and gnere subclasses. Organization is key for user likeability so this will be very beneficial to help establish organization of the objects while still having robust identification from the beginning.



 <br />

 > ## Phase II
 > See "Projects" to view the Kanban board.
## Class Diagram
 > [class diagram](https://github.com/cs100/final-project-hnp/blob/master/Project%20Class%20Diagram.pdf)
 
 > ## Phase III
 > * In the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did):<br />
 Our last sprint was effective. Even though we had midterms and were only able to accomplish around 60-75% of what we had originally planned, what we had planned on  our first sprint allowed us to still stay on track and make an effort to not lag behind. 
 
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint:<br />
We did not complete our implementation of our strategy and factory pattern (sorting functions as well as creating classes), and we definitely took these into consideration for this sprint. We created kanban issues to brainstorm ideas on how to resolve these blockers. When creating the class diagram, we thought the patterns would be easier to implement, but the more we coded, the more we realized we had more problems to account for. 

 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority? <br />
For the next sprint, we plan on beginning to create test cases for each of the files. We also found out that we will need to design our composite pattern a bit differently, and ended up changing the different variables within the objects. However, the objects themselves should remain the exact same. One bug or challenge we encountered was creating the constructors for the Movie, Category, and Media classes. We plan on taking this into account into the next sprint by emphasizing massive work in these areas, as well as focusing more time on developing the factory pattern to suit this project.  
One major “wall” we ran into was implementing the Strategy pattern, in which we had to account for a lot more factors we didn’t originally know we had to look out for. Our recAlgo class, in theory, would end up conflicting with what our sortAlgo class did, as both classes have a lot of overlap, so we are thinking of just combining the two abstract classes to make a single Algo class. We are currently still brainstorming together to get this part of the strategy pattern sorted out. 

 > * What tasks you are planning for this next sprint. <br />
 > - Start writing unit tests for different classes (for Media.hpp, Movie.hpp, etc.).
 > - Work on breaking the wall for strategy pattern (Possibly combine recAlgo and sortAlgo).
 > - Organize and clean up dataset.
 > - Work on breaking the wall for factory pattern. 
 

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
![option1](https://user-images.githubusercontent.com/57116759/101769096-52e4cb80-3a9b-11eb-922e-84a017bf2e86.png)
> * This is our first option, where we present to the user the top 10 rated movies.
![option2](https://user-images.githubusercontent.com/57116759/101769103-55472580-3a9b-11eb-9c64-a97d68df8850.png)
> * This is our second option, where we present to the user the top 10 actor-related movies.
![option3](https://user-images.githubusercontent.com/57116759/101769112-5710e900-3a9b-11eb-89dc-1f9917956df2.png)
> * This is our third option, where we present to the user the top 10 genre-related movies movies.
![option4](https://user-images.githubusercontent.com/57116759/101769129-5c6e3380-3a9b-11eb-97b3-9206d5b95938.png)
> * This is our fourth option, where we present prompt the user for a movie and will recommend them recommendations based through the alogrithm we created, which takes into account director, actors, and genres.
![option4pt2](https://user-images.githubusercontent.com/57116759/101769136-5f692400-3a9b-11eb-8281-f5a8e06d0a6d.png)
> * This is another input/output from our fourth option. 
![option4pt3](https://user-images.githubusercontent.com/57116759/101769141-6132e780-3a9b-11eb-98b9-8c4fb57585ba.png)
> * This is another input/output from our fourth option. 
![option5](https://user-images.githubusercontent.com/57116759/101769146-642dd800-3a9b-11eb-9077-08ef7e632926.png)
> * This is our fifth option, where we present to the user the top 10 most recent movies.
![option6](https://user-images.githubusercontent.com/57116759/101769148-655f0500-3a9b-11eb-80e5-e312ab70b260.png)
> * This is our sixth option, where we present to the user the top 10 director-related movies.

 ## Installation/Usage
 > To be able to run our program, [boost library](https://www.boost.org/) must be installed on your machine.
 <br /> To use our program, simply download VS Code or another IDE to run (Boost library does not work on hammer):
 <br /> Download our files
 <br /> Run the code in the terminal, by typing "g++ main.cpp DisplayStrategy.cpp Factory.cpp Media.hpp Movie.cpp -std=c++11"
 <br /> Run ./a.out
 <br />Afterwards, a menu appears and you simply input the option you want. With this program, you should have brand new movies that you will most likely like to watch!
 ## Testing
 > We used gtest to test our program. 
