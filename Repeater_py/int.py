import re
import os
import subprocess,sys

memstack = []
def generate_lines(address):
        f_open=open(address, "r")
        lines=str(f_open.read()).split('\n')
        return lines

def generate_opcode_line(opCodes):
        address="opcodes.txt"
        f=open(address, "w")
        for i in opCodes:
                f.write(str(i)+str('\n'))
        f.close()

def generate_token(lines):
        arr=lines[0].split('=')
        return arr[len(arr)-1].strip()

def generate_opcode(lines):
        regex, opcode, opinit=r''+token, [], 0
        for i in range(1, len(lines)):
                if lines[i].find("rip")!=-1:
                        opcode.append(0)
                        continue
                elif lines[i].find("op_a")!=-1:
                        opinit=0
                elif lines[i].find("op_b")!=-1:
                        opinit=10
                elif lines[i].find("op_io")!=-1:
                        opinit=20
                elif lines[i].find("op_log")!=-1:
                        opinit=30
                elif lines[i].find("op_lalp")!=-1:
                        opinit=96
                elif lines[i].find("op_ualp")!=-1:
                        opinit=64         
                arr=re.findall(regex, lines[i])
                opcode.append(int(len(arr)+opinit))
        return opcode

# def interpret(opCodes):
#       i=0
#       while i<len(opCodes):
#               if opCodes[i]==1
#               i++

# Driver code
def generate_operation():
        for i in range(len(opCodes)):
                if opCodes[i] == 0:
                        sys.exit(0)
                elif opCodes[i] == 1:
                        if memstack[len(memstack)-1].isdigit() and memstack[len(memstack)-2].isdigit():
                                x = float(memstack[len(memstack)-1]) + float(memstack[len(memstack)-2])
                                memstack.append(str(x))
                        else:
                                y = memstack[len(memstack)-1]+memstack[len(memstack)-2]
                                memstack.append(y)
                elif opCodes[i] == 2:
                        if memstack[len(memstack)-1].isdigit() and memstack[len(memstack)-2].isdigit():
                                x = float(memstack[len(memstack)-1]) - float(memstack[len(memstack)-2])
                                memstack.append(str(x))
                        else:
                                print("Operation not possible")
                elif opCodes[i] == 3:
                        if memstack[len(memstack)-1].isdigit() and memstack[len(memstack)-2].isdigit():
                                x = float(memstack[len(memstack)-1]) * float(memstack[len(memstack)-2])
                                memstack.append(str(x))
                        else:
                                print("Operation not possible")         
                elif opCodes[i] == 4:
                        if memstack[len(memstack)-1].isdigit() and memstack[len(memstack)-2].isdigit():
                                x = float(memstack[len(memstack)-1]) / float(memstack[len(memstack)-2])
                                memstack.append(str(x))
                        else:
                                print("Operation not possible") 
                elif opCodes[i] == 21:
                        x = input("Input an element:")
                        memstack.append(x)
                elif opCodes[i] == 22:
                        print(memstack[len(memstack)-1])
                elif opCodes[i] >= 97 and opCodes[i] <= 122:
                        print(chr(opCodes[i]),end = "")
                elif opCodes[i] >= 65 and opCodes[i] <= 90:
                        print(chr(opCodes[i]),end = "")        
print("Enter address of the file: ", end="")
address=input()
lines=generate_lines(address)
token=generate_token(lines)
opCodes=generate_opcode(lines)
print(opCodes)
generate_opcode_line(opCodes)
generate_operation()
