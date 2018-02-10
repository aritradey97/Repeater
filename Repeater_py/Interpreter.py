import re,os
def generate_lines(address):
	f_open = open(address, "r")
	lines = str(f_open.read().split())
	return lines
def generate_token(lines):
	arr = lines[0].split('=')
	return arr[len(arr) - 1]
def generate_opcode(lines):
	regex = r'abc'
	reg = []
	arr = re.findall(regex, lines[1])
	reg.append(len(arr))
	return reg	
address = raw_input("Enter address of the file:")
lines = generate_lines(address)
token = generate_token(lines)
opcodes = generate_opcode(lines)
print opcodes