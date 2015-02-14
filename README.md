Array Left-Shift Algorithm
==========================

Motivation
----------

On February 12, 2015, I attended a job fair and rigorously marketed myself to different companies in search of a summer internship. It's no secret that I've spent most of my college career focused on pure academia, and getting a solid industry job requires far more than just theoretical skills. I ended up very luckily landing an interview with a company the very next day (a company whose name I will not disclose here, out of courtesy for them, if they ever choose to ask this question in the future), and during the technical portion of the interview, I was almost completely stumped by this very simple question.

It wasn't a very tough question at all.

Nonetheless, I panicked, and ended up coming up with a lot of abstract, theoretical talk about what *wouldn't* work and why it wouldn't work at all. I was all over the place, and I started coming up with halves of ideas here and there, unable to settle down on anything concrete. Having to code it up on the board was another thing entirely.

However, I did have some ideas for approaching this problem, and the interviewer felt that one of my approaches was slightly different from what he had in mind. It would have been a clever algorithm, had I implemented it there. Of course, I panicked and loss all sense of my basic fundamentals, and ended up running out of time. In the end, I asked what his approach would have been, and it was laughably obvious. I beat myself over it for the remainder of the day.

Hours later, after feeling sufficiently disappointed in myself, I ended up sitting down and coding up the problem very thoroughly. I tried to attack it from all angles, finishing up what I had started earlier in the day. I wouldn't go down without a fight, and my thirst to deeply understand everything in my path wouldn't let me go. It's probably a bit of my obsessive-compulsiveness that drives me to master everything I don't know. Lack of knowledge scares me, after all. In any case, I ended up working with a few different approaches (and languages) just to push myself to practice my technical skills harder. This is the product of those efforts.

In this repository, I have four scripts to accomplish the algorithm at hand, and one script just for basic set-up. During the interview, my main language of choice was C, which presented some dramatic on-the-spot issues. Although C and C++ are my primary languages, they were not as tidy as scripting languages (especially Python and Matlab in mind). Since there was a much easier way to finish the problem using Python, I sat down and practiced more of that language to get a solution in Python as well. Two other scripts are in C++, and one (my favorite) is in C, since it is simple enough to implement there.

But what exactly was the problem that I was stumped on so strongly, that actually was quite trivial in the end? Read on.
 
The Problem
-----------

Say you have an array of numbers, as shown below.

[ 0 1 2 3 4 ]

You need to write some code that left-shifts the array a specified amount.  
For example, if you specified a rotation of 2, the new array would be:

[ 2 3 4 0 1 ]

How would you efficiently write code to do this shifting?

> *Something extra:* Say you had a very large amount of data, such as millions of numbers or more. How would you do the left shift with the data then? What practical obstacles would you face in working with that amount of data?

My Initial Thoughts
-------------------

Since I've very recently worked on embedded programming (of which I actually have code for in a different repository on GitHub), the first thing that came to mind is the fact that this sounds like an easy problem to resolve using circular arrays. When operating within the paradigm of that 'data structure', the logical thing (for me, at least) is to think of arithmetic operations (namely modular arithmetic) to get the indices shifted over properly.

In my mind, all I needed to do was `(index - shiftamount) % arraysize`. Nothing crazy.

However, it's a bit more complicated than that to actually implement it. I originally did not want to use a second array, so I tried writing the elements to the back while reading the elements from the front. For obvious reasons, that was a no-go.

And then I figured out it would be a lot easier if I used a second array, which was a bit of a disappointment to me, but I tried to work with that. I ended up stumbling around for quite a while, and falling flat on my face when the interviewer asked what would happen if I was given an extremely large set of data.

I knew that it would easily cause a stack overflow, so I couldn't practically work with it all in a single array at once. I had to break it up somehow. But at the time, it was all a mystery to me. He eventually gave me the answer, but by then it was all too late. My time was up, and I had yet struggled to come up with anything tangible (beyond the mathematical equation above, of course).

Once I sat down at the computer, equipped with the benefit of time and lack of in-the-moment pressures, I was able to hack some very simple, silly scripts up to solve the problem at hand. These are explained in the following section.

Explanation of the Code
-----------------------

I came up with four scripts to accomplish the left shift for elements.

Originally, I came up with two solutions in C++, but I realized that one was simple enough to implement in C, so that's where the first script (arrayshift1.c) comes from. The second script (arrayshift2.cpp) is really just a straight-forward, brute-force method of approach. The third script is written in Python, since it has a pretty trivial way of solving the problem, and it was good practice on my part to get more familiar with a scripting language. Finally, to deal with the issue of large quantities of data (upwards of a million elements), I wrote a script in C++ (arrayshift4.cpp) to work with text files and minimize use of space allocation on the stack.

I explain each script in more detail below.

Furthermore, there's no point in hiding my code from others. If I'm a bad coder, I need to know it. The more people who critique my work, the more I will actually be able to learn from my mistakes and grow. That's really the best approach to becoming more technically skilled in my mind, since I rather do stupid things in my leisure than during a technical interview or when I'm actually on a team facing a deadline. *Everyone has to start somewhere, and more often than not, it takes hundreds of programs of shitty code critiqued by others to learn how to be a good coder.*

With this philosophy in mind, I've posted this repository with my code here for all to see. **I encourage my friends and colleagues to take a look at my code (and run it, if you wish). I am open to suggestions as well as comments.**

For added bonus, I've got a nice table below to summarize some basic facts about each algorithm:

Script Name | Script Language | Time Complexity | Space Complexity
----------- | --------------- | --------------- | ----------------
arrayshift1 |               C |            O(n) |             O(n)
arrayshift2 |             C++ |            O(n) |             O(n)
arrayshift3 |          Python |            O(n) |             O(n)
arrayshift4 |             C++ |            O(n) |             O(s)
arrayshift5 |             C++ |            O(s) |             O(n)
arrayshift6 |          Python |            O(s) |             O(n)

> Note: 's' in the last three algorithms denote the amount you wish to shift by.  

### arrayshift1.c

This code is extremely straightforward, and is an implementation of the solution I started out with during the interview using modular arithmetic. A few obstacles arose during the writing of this script, including the realization that C/C++ allows for modulo to evaluate to a negative expression (unlike Python, which does what we would normally mathematically expect). I was able to work around this and make a pretty elegant solution.

> **Code Golf:** Using my algorithm, this problem really just reduces to a one-liner at its core. When looking at it now, in hindsight, the solution is just so laughably simple that I really wish I was able to crank it out on the spot. Here's that one line of code:  
`for (int i = 0; i < size; i++) { arr2[((i - shift) % size + size) % size] = arr[i]; }`
given that *arr2* is the new array, instantiated to the same size of the first array, *arr*. The way to find size in C is a bit cute as well, which is:  
` int size = sizeof(arr) / sizeof(int); `

### arrayshift2.cpp

This is pretty much a brute-force approach that uses vectors instead of arrays to deal with the problem at hand. There's nothing fancy here. This is probably the least elegant and least interesting of these scripts, but it was still worth going through and cranking out. I might sit down and think more deeply about how I could use less space if I were to use the vector data structure.

(Of course, if I used a deque data structure in C++, I could easily just do a series of `pop_front()` and `push_back()` calls to take everything from the front and stick it to the back of the deque. Of course, this would be the absolute easiest/fastest way to do it in C++. However, I wanted to stick to something closer to a simple array to limit myself.)

### arrayshift3.py

Of course, Python wins with the most efficient way to type up this algorithm:

` array = array[amount:] + array[:amount] `

I'm not necessarily sure if this would even have been an interesting question for me if I had more experience with lists in Python. A Python coder might find this question completely trivial and laughable, I would suspect.

Of course, Python does come with its disadvantage of speed, since it requires an interpreter, versus C/C++ which can be optimized by a compiler.

### filltextfile.cpp

*You need to run this script first, before running `arrayshift4.cpp`.*

This script is here just to (create and) file a text file with as many numbers as the user desires (up to the amount that can be stored by ints, of course). I decided to keep it simple and just stick in the numbers sequentially, but a `Math.random()` sort of thing could definitely have been used to mimic real "Big Data" sets.

### arrayshift4.cpp

Finally, the most interesting script of all is the one that works with a left shift for large quantities of elements. Nothing really fancy goes on here, except that I go through a single text file and write into a secondary text file at the same time. This code currently does have the constraint of having to store some of the elements in a vector, but that's dramatically less space on the stack than any of the previous three algorithms.

(For instance, say we desire shifting by 100 elements out of a set of 1,000,000 elements. The other algorithms would require storing those 1,000,000 elements on the stack, while this algorithm only requires storing 100 elements on the stack.)

I do wish to figure out a better method of doing this, that doesn't require using the vector, of course. Dealing with file I/O in C++ hasn't been my specialty, but this is definitely a good way to practice it.

### arrayshift5.cpp

I decided to add this one in, just because it was the obvious "no-duh" answer that used a `deque<int>` with `pop_front()` and `push_back()`. Of course, my assumption during the interview was that I'd be limited to an array data structure, but I definitely should have at least brought this one up.

The curious thing with deques is how to count the runtime and space complexity with it. You could make different arguments based on different implementations of deques, and if you're using an implementation with a doubly-linked list, I could see how each `pop_front()` and `push_back()` could be done in constant time. With that being said, a total runtime of `O(s)` would result, blowing everything else out of the water in terms of *theoretical* speed.

### arrayshift6.cpp

It also comes to my attention (with thanks of my good friend Kevin Chung) that lists in Python have the capabilities of deques as well, which makes life incredibly easier. As opposed to having to use list slicing, which takes time and space, you can just call `array.append(array.pop(0))` in a loop just as you would in C++ with the deque approach.

Again, not sure how far from the bounds of the question I'd be going by using the deque approach, but since the list is one of the most fundamental structures in Python to use, I'm sure this would be entirely valid and extremely efficient as well. So it was worth coding up to see it work.