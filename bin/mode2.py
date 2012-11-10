import sys
import random

note_file = open(sys.argv[1])
note_lines = note_file.readlines()
note_file.close()

lines = list()

for line in note_lines:

	line = line.strip()
	lines.append(line)
	random.shuffle(lines)
	output = "\n".join(lines)

	file('output.txt','w').write(output)
