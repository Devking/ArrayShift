# Written by Wells Lucas Santo
# 13 February 2015

def rotate(amount, array):
	# python lets us use list slicing, which makes life easier than in C/C++
	# array[amount:] will give us the elements from index "amount" to the end
	# array[:amount] will give us the elements up to index "amount" (non-inclusive)
	# note that python lists are mutable, so i need to return the "new list"
	# changes made to lists (which are otherwise passed by reference) do not stick
    return array[amount:] + array[:amount]

# again, just hardcoding the list initialization, but this could
# easily be constructed by taking user input
# this list can easily be changed without the rest of the coding needed to change
someList=[0,1,2,3,4]
shift = input("Shift by how much? ")
print "Original List:"
print someList[:]
# make sure that the shift amount is valid
shift %= len(someList)
someList = rotate(shift, someList)
print "Shifted List:"
print someList[:]

# though python is definitely more succinct than c/c++,
# a lot goes under the hood that a python coder does not acknowledge
# for example, the list slices make copies, and at the end of the day.
# thus, this algorithms will still require "n" space complexity

# ...also, python is a slower language to run than c/c++ due to using an
# interpreter rather than a compiler, as well as having dynamic typing
# instead of static typing