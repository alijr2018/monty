#!/usr/bin/python3
def text_to_brainfuck(text):
    brainfuck_code = ""
    for char in text:
        ascii_value = ord(char)
        brainfuck_code += "+" * ascii_value + ".>"

    return brainfuck_code

text = "School\n"
brainfuck_code = text_to_brainfuck(text)

filename = "1000-school.bf"
with open(filename, "w") as file:
    file.write(brainfuck_code)

print("Brainfuck code has been saved to", filename)

