# COS214-Prac-4

We split the prac into 3 sections labelled member 1, 2, and 3

Hierarchical work processing system for a film production domain. A production is organised into Units and Sequences (nested groups of CompositeComponent), which contain individual Shots (leaves). A shot moves through a filming lifecycle and can have optional responsibilities (VFX, stunt coordination, security, insurance) atttached at runtime.

Four GoF patterns are used together as one system:  
- Composite
- Iterator
- State
- Decorator

# Member 1



# Member 2

# Member 3 

## Member 3 Files

`ComponentDecorator.h/.cpp` - Abstract Decorator, wraps a component.
`VFXDecorator`, `StuntCoordinationDecorator`, `SecurityDecorator`, `InsuranceDecorator` (each .h/.cpp) - Concrete decorators, all stackable in any order.

## Ownership 

Each Deorator own the Component it wraps and deletes it in its own destructor. Deleting the outermost decorator in a stack cascades down through every layer, includeing the underlying Shot or 
CompositeComponent. This mirrors the ownership policy for the Composite Tree, so the whole object graph follows one rule. Whoever holds a component is responsible for deleting it exactly once.

# Build/Run

make
./taskforge

# Docker

docker build -t taskforge .
docker run --rm -it taskforge

# GDB

docker run --rm -it taskforge bash
gdb ./taskforge
(gdb) break main
(gdb) run
(gdb) next

# Valgrind

docker run --rm -it taskforge bash
valgrind --leak-check=full --show-leak-kinds=all ./taskforge

