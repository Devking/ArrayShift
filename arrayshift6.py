def rotate(amount, array):
    for x in range(0, amount):
    	# working with the list as if it was a deque
        array.append(array.pop(0))
    return array

someList = [0,1,2,3,4,]
shift = input("Shift by how much? ")
print "Original List:"
print someList[:]
# make sure that the shift amount is valid
shift %= len(someList)
someList = rotate(shift, someList)
print "Shifted List:"
print someList[:]