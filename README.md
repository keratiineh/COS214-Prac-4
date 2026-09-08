# COS214-Prac-4

Team:
- Christain Khaled (Member 1) - u25420314
- Rati Molefe (Member2) - u25324170
- Janke Rall (Member 3) - u24571238

We split the prac into 3 sections labelled member 1, 2, and 3

Hierarchical work processing system for a film production domain. A production is organised into Units and Sequences (nested groups of CompositeComponent), which contain individual Shots (leaves). A shot moves through a filming lifecycle and can have optional responsibilities (VFX, stunt coordination, security, insurance) atttached at runtime.

Four GoF patterns are used together as one system:  
- Composite
- Iterator
- State
- Decorator

# Member 1

## Composite & Iterator 

`Component` is the shared abstraction (`getId()`, `getName()`, `getStatus()`,
`createIterator()`). `CompositeComponent` owns a `vector<Component*>` of
children and deletes them in its destructor; `Shot` is the leaf and returns
`nullptr` from `createIterator()`. Two independent traversal strategies exist
over the same tree: `FullTraversalIterator` (visits everything) and
`SelectiveTraversalIterator` (visits only components matching a status
string). Both build their item list eagerly in the constructor, which makes
traversal snapshot-based - see the note on runtime changes below.

# Member 2

## State

`Shot` owns its current `ShotState` via composition and is the only place
that allocates or deletes one, keeping lifecycle memory management in a
single spot. `ShotState::checkTransition()` is the one action method: each
concrete state returns a freshly-allocated instance of the next state if a
transition is legal, or `nullptr` if not (e.g. `ApprovedState` is terminal).
Lifecycle order: `ScheduleState -> ShootingState -> CompletedState ->
InPostState -> ApprovedState`.

# Member 3

## Decorator 

`ComponentDecorator` wraps a single `Component` and owns it, so deleting the
outermost decorator in a stack cascades down through every layer including
the underlying `Shot`. Only `getStatus()` is overridden by concrete
decorators to append their own text; `getId()`/`createIterator()` pass
straight through to the wrapped component, so a decorated Shot stays usable
anywhere a plain Shot would be - including inside a `CompositeComponent`.
Four decorators are stackable in any order: `VFXDecorator`,
`StuntCoordinationDecorator`, `SecurityDecorator`, `InsuranceDecorator`.

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

