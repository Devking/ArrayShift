Array Left-Shift Algorithm
==========================

Motivation
----------

On February 12, 2015, I attended a job fair and rigorously marketed myself to different companies in search of a summer internship. It's no secret that I've spent most of my college career focused on pure academia, and getting a solid industry job requires far more than just theoretical skills. I ended up very luckily landing an interview with a company the very next day (a company whose name I will not disclose here, out of courtesy for them, if they ever choose to ask this question in the future), and during the technical portion of the interview, I was almost completely stumped by this very simple question.

It wasn't a very tough question at all.

Nonetheless, I panicked, and ended up coming up with a lot of abstract, theoretical talk about what *wouldn't* work and why it wouldn't work at all. I was all over the place, and I started coming up with halves of ideas here and there, unable to settle down on anything concrete. Having to code it up on the board was another thing entirely.

However, I did have some ideas for approaching this problem, and the interviewer felt that one of my approaches was slightly different from what he had in mind. It would have been a clever algorithm, had I implemented it there. Of course, I panicked and loss all sense of my basic fundamentals, and ended up running out of time. In the end, I asked what his approach would have been, and it was laughably obvious. I beat myself over it for the remainder of the day.

Hours later, after feeling sufficiently disappointed in myself, I ended up sitting down and coding up the problem very thoroughly. I tried to attack it from all angles, finishing up what I had started earlier in the day. This is the product of those efforts.

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

In my mind, all I needed to do was `index - shiftamount % arraysize`. Nothing crazy.

However, it's a bit more complicated than that to actually implement it. I originally did not want to use a second array, so I tried writing the elements to the back while reading the elements from the front. For obvious reasons, that was a no-go.

And then I figured out it would be a lot easier if I used a second array, which was a bit of a disappointment to me, but I tried to work with that. I ended up stumbling around for quite a while, and falling flat on my face when the interviewer asked what would happen if I was given an extremely large set of data.

I knew that it would easily cause a stack overflow, so I couldn't practically work with it all in a single array at once. I had to break it up somehow. But at the time, it was all a mystery to me. He eventually gave me the answer, but by then it was all too late. My time was up, and I had yet struggled to come up with anything tangible (beyond the mathematical equation above, of course).

Once I sat down at the computer, equipped with the benefit of time and lack of in-the-moment pressures, I was able to hack some very simple, silly scripts up to solve the problem at hand. These are explained in the following section.

Explanation of the Code
-----------------------

### arrayshift1.c

### arrayshift2.cpp

### arrayshift3.py

### filltextfile.cpp

### arrayshift4.cpp