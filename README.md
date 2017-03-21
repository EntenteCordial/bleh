# programming language

a basic programming language intepreter

# Syntax

## expressions

### arithmetic

```
A [operator] B
```

where A is `+`, `-`, `*`, `/`

### call function

```
identifier([arguments])
```

## commands

## definition

```identifier = [string]/[int];```

## function

```
function identifier([arguments]){
	[commands]
}
```

## flow controls

### if

```
if([condition]){
	[commands]
}
```

### while

```
while([condition]) {
	[commands]
}
```

# Grammar

```
program := command*

command :=
	definition_command |
	call_command |
	if_command |
	function_command |
	while_command

definition_command := identifier "=" expression ";"

arguments := "(" expression ("," expression)* ")"
identifier_arguments := "(" identifier ("," identifier)* ")"
call_command := identifier arguments 
function_command := "function" identifier identifier_arguments block

if_command := "if" "(" expression ")" block
while_command := "while" "(" expression ")" block
block := "{" command* "}"
```

# Example

## Hello World

```
print("Hello World");
```
