import sys
import random

note_file = open(sys.argv[1])
note_lines = note_file.readlines()
note_file.close()

for line in note_lines:

	line = line.strip()
	words = line.split(" ")
	random.shuffle(words)
	output = " ".join(words)

	file('output.txt','w').write(output)
