# 🧩 Low-Level Design (LLD) — Complete Guide

> A complete Low-Level Design roadmap covering **OOP, SOLID, Design Principles, UML, Design Patterns, Enterprise Patterns, Concurrency Patterns, Distributed System Patterns, and real-world LLD problems**.

---
<img width="1024" height="1536" alt="image" src="https://github.com/user-attachments/assets/edf19960-1582-4394-a601-fa9b91bbd686" />

# 📚 Table of Contents

* [1. What is LLD?](#1-what-is-lld)
* [2. LLD vs HLD](#2-lld-vs-hld)
* [3. OOP Fundamentals](#3-oop-fundamentals)
* [4. Relationships Between Objects](#4-relationships-between-objects)
* [5. SOLID Principles](#5-solid-principles)
* [6. Other Design Principles](#6-other-design-principles)
* [7. UML](#7-uml)
* [8. Design Patterns](#8-design-patterns)
* [9. Creational Patterns](#9-creational-patterns)
* [10. Structural Patterns](#10-structural-patterns)
* [11. Behavioral Patterns](#11-behavioral-patterns)
* [12. Enterprise/Application Patterns](#12-enterpriseapplication-patterns)
* [13. Concurrency Patterns](#13-concurrency-patterns)
* [14. Distributed System Patterns](#14-distributed-system-patterns)
* [15. Dependency Injection](#15-dependency-injection)
* [16. Layered Architecture](#16-layered-architecture)
* [17. Clean Architecture](#17-clean-architecture)
* [18. Domain-Driven Design Basics](#18-domain-driven-design-basics)
* [19. LLD Design Process](#19-lld-design-process)
* [20. LLD Problem-Solving Framework](#20-lld-problem-solving-framework)
* [21. LLD Case Studies](#21-lld-case-studies)
* [22. Pattern Mapping](#22-pattern-mapping)
* [23. Concurrency & Thread Safety](#23-concurrency--thread-safety)
* [24. Error Handling](#24-error-handling)
* [25. Testing LLD](#25-testing-lld)
* [26. Code Quality](#26-code-quality)
* [27. LLD Interview Preparation](#27-lld-interview-preparation)
* [28. Complete Learning Checklist](#28-complete-learning-checklist)

---

# 1. What is LLD?

**Low-Level Design (LLD)** describes the internal structure of a software system.

LLD focuses on:

* Classes
* Objects
* Interfaces
* Methods
* Attributes
* Relationships
* Responsibilities
* Design patterns
* Object interactions
* Business rules
* Error handling
* Extensibility
* Testability

Example:

```text
Parking Lot
      ↓
ParkingLot
ParkingFloor
ParkingSpot
Vehicle
Ticket
Payment
Gate
ParkingStrategy
```

LLD answers:

> "How exactly should this system be implemented?"

---

# 2. LLD vs HLD

| LLD                     | HLD                  |
| ----------------------- | -------------------- |
| Classes                 | Services             |
| Objects                 | Databases            |
| Interfaces              | Load Balancers       |
| Methods                 | Caches               |
| Design Patterns         | Message Queues       |
| Object relationships    | Microservices        |
| UML                     | Scalability          |
| Code structure          | Infrastructure       |
| Detailed implementation | Overall architecture |

### LLD

```text
Class → Object → Interface → Method → Pattern
```

### HLD

```text
Client → API Gateway → Services → Cache → Database
```

---

# 3. OOP Fundamentals

Before learning LLD, understand Object-Oriented Programming.

---

## 3.1 Class

A class is a blueprint for creating objects.

```text
class Car
    ├── brand
    ├── speed
    ├── start()
    └── stop()
```

---

## 3.2 Object

An object is an instance of a class.

```text
Car car1
Car car2
```

---

## 3.3 Encapsulation

Bundle data and behavior together and control access to internal state.

```text
Car
 ├── private speed
 ├── increaseSpeed()
 └── decreaseSpeed()
```

---

## 3.4 Abstraction

Expose essential behavior while hiding implementation details.

```text
Payment
   ↓
pay()
```

The caller does not need to know how payment processing works internally.

---

## 3.5 Inheritance

A child class inherits behavior from a parent class.

```text
Vehicle
   ↑
   |
  Car
```

Use inheritance only when a genuine **is-a** relationship exists.

---

## 3.6 Polymorphism

The same interface can have different implementations.

```text
Payment
   ↑
 ┌─┴─────────┐
 ↓           ↓
CardPayment  UPIPayment
```

---

## 3.7 Composition

One object contains another object.

```text
Car
 └── Engine
```

Prefer composition over inheritance when appropriate.

---

## 3.8 Aggregation

A weak whole-part relationship.

```text
University
 └── Students
```

Students can exist independently of the university object.

---

## 3.9 Association

A general relationship between objects.

```text
Teacher ───── Student
```

---

# 4. Relationships Between Objects

Understand:

```text
Association
Aggregation
Composition
Inheritance
Dependency
Realization
```

### Relationship hierarchy

```text
Association
    │
    ├── Aggregation
    │
    └── Composition
```

---

# 5. SOLID Principles

SOLID is one of the most important foundations of LLD.

---

# 5.1 Single Responsibility Principle — SRP

> A class should have one primary responsibility.

Bad:

```text
User
 ├── saveToDatabase()
 ├── sendEmail()
 ├── generateReport()
 └── calculateSalary()
```

Better:

```text
User
UserRepository
EmailService
ReportService
SalaryService
```

---

# 5.2 Open/Closed Principle — OCP

> Software entities should be open for extension but closed for modification.

Instead of constantly modifying:

```text
PaymentService
```

create:

```text
PaymentStrategy
      ↑
 ┌────┼──────────┐
 ↓    ↓          ↓
Card UPI        Cash
```

---

# 5.3 Liskov Substitution Principle — LSP

> Subtypes must be usable wherever their base type is expected without breaking correctness.

Avoid inheritance when the child cannot honor the parent's contract.

---

# 5.4 Interface Segregation Principle — ISP

> Clients should not depend on interfaces they do not use.

Bad:

```text
Worker
 ├── work()
 ├── eat()
 └── sleep()
```

Better:

```text
Workable
Eat
Sleep
```

---

# 5.5 Dependency Inversion Principle — DIP

> High-level modules should depend on abstractions, not concrete implementations.

Bad:

```text
OrderService → MySQLDatabase
```

Better:

```text
OrderService
      ↓
DatabaseRepository
      ↑
 ┌────┴────┐
MySQL   MongoDB
```

---

# 6. Other Design Principles

## DRY

**Don't Repeat Yourself**

Avoid duplicate logic.

---

## KISS

**Keep It Simple, Stupid**

Prefer simple designs when complexity provides no benefit.

---

## YAGNI

**You Aren't Gonna Need It**

Don't build unnecessary functionality.

---

## Separation of Concerns

Different responsibilities should remain separated.

---

## Composition Over Inheritance

Prefer composing behavior over creating deep inheritance trees.

---

## Encapsulate What Varies

Identify behavior that changes frequently and isolate it.

---

## Program to an Interface

Depend on abstractions.

```text
PaymentService
     ↓
Payment
```

rather than:

```text
PaymentService
     ↓
StripePayment
```

---

## Law of Demeter

An object should have limited knowledge about other objects.

Avoid excessive chains:

```text
a.getB().getC().getD().doSomething()
```

---

## Principle of Least Knowledge

Minimize dependencies between components.

---

## Favor Immutability

Immutable objects are easier to reason about and safer in concurrent systems.

---

# 7. UML

UML helps visualize LLD before implementation.

---

## 7.1 Class Diagram

Shows:

* Classes
* Attributes
* Methods
* Relationships

Example:

```text
+-------------------+
|      Vehicle      |
+-------------------+
| - number          |
| - type            |
+-------------------+
| +getNumber()      |
| +getType()        |
+-------------------+
```

---

## 7.2 Sequence Diagram

Shows interactions over time.

```text
Client
  |
  | request()
  ↓
Controller
  |
  | process()
  ↓
Service
  |
  | save()
  ↓
Repository
```

---

## 7.3 Use Case Diagram

Shows:

* Actors
* Use cases
* System boundary

---

## 7.4 Activity Diagram

Shows workflow.

```text
Start
 ↓
Login
 ↓
Validate
 ↓
Success?
 ├── Yes → Dashboard
 └── No  → Error
```

---

## 7.5 State Diagram

Shows state transitions.

```text
Created
   ↓
Paid
   ↓
Processing
   ↓
Completed
```

---

## 7.6 Component Diagram

Shows high-level components and dependencies.

---

## 7.7 Deployment Diagram

Shows where components are deployed.

---

# 8. Design Patterns

Design patterns are reusable approaches to recurring design problems.

There are **23 classic Gang of Four (GoF) patterns**.

They are divided into:

```text
Creational
Structural
Behavioral
```

---

# 9. Creational Patterns

There are 5 GoF creational patterns.

```text
1. Singleton
2. Factory Method
3. Abstract Factory
4. Builder
5. Prototype
```

---

# 9.1 Singleton

Ensures a class has one shared instance.

### Structure

```text
Client
  ↓
Singleton
  ↓
Single Instance
```

### Examples

* Logger
* Configuration Manager
* Application-wide registry

### Problems

* Global state
* Difficult testing
* Hidden dependencies
* Concurrency concerns

Use carefully.

---

# 9.2 Factory Method

Creates objects without exposing object creation logic.

```text
PaymentFactory
      |
 ┌────┼──────┐
 ↓    ↓      ↓
Card UPI    Cash
```

Useful when object creation varies.

---

# 9.3 Abstract Factory

Creates families of related objects.

```text
GUIFactory
 ├── WindowsFactory
 └── MacFactory
```

Each factory can create:

```text
Button
Checkbox
Menu
```

---

# 9.4 Builder

Constructs complex objects step-by-step.

```text
UserBuilder
    ↓
setName()
    ↓
setEmail()
    ↓
setAge()
    ↓
build()
```

Useful when objects have many optional parameters.

---

# 9.5 Prototype

Creates new objects by cloning existing objects.

Useful when:

* Object creation is expensive
* Many similar objects are required

---

# 10. Structural Patterns

There are 7 GoF structural patterns.

```text
1. Adapter
2. Bridge
3. Composite
4. Decorator
5. Facade
6. Flyweight
7. Proxy
```

---

# 10.1 Adapter

Makes incompatible interfaces work together.

```text
Client
 ↓
Target Interface
 ↓
Adapter
 ↓
Legacy System
```

Example:

```text
OldPaymentAPI
      ↓
PaymentAdapter
      ↓
NewPaymentInterface
```

---

# 10.2 Bridge

Separates abstraction from implementation.

```text
Abstraction
     |
     ↓
Implementation
```

Useful when both abstraction and implementation can vary independently.

---

# 10.3 Composite

Treat individual objects and groups of objects uniformly.

Perfect for tree structures.

Example:

```text
FileSystem
   ├── Folder
   │    ├── File
   │    └── File
   └── Folder
```

---

# 10.4 Decorator

Adds behavior dynamically without modifying the original class.

Example:

```text
Coffee
 ↓
MilkDecorator
 ↓
SugarDecorator
 ↓
ChocolateDecorator
```

---

# 10.5 Facade

Provides a simple interface over a complex subsystem.

```text
Client
  ↓
PaymentFacade
  ├── Validate
  ├── Payment
  ├── FraudCheck
  └── Receipt
```

---

# 10.6 Flyweight

Shares common state between many objects to reduce memory usage.

Useful for:

* Text editors
* Game objects
* Large numbers of similar objects

---

# 10.7 Proxy

Provides a substitute/control layer for another object.

Types:

* Virtual Proxy
* Protection Proxy
* Remote Proxy
* Caching Proxy

Examples:

* Lazy loading
* Access control
* Caching
* Remote service access

---

# 11. Behavioral Patterns

There are 11 GoF behavioral patterns.

```text
1. Chain of Responsibility
2. Command
3. Interpreter
4. Iterator
5. Mediator
6. Memento
7. Observer
8. State
9. Strategy
10. Template Method
11. Visitor
```

---

# 11.1 Chain of Responsibility

Passes a request through a chain of handlers.

```text
Request
  ↓
Handler 1
  ↓
Handler 2
  ↓
Handler 3
```

Examples:

* Authentication pipeline
* Logging
* Validation
* Middleware

---

# 11.2 Command

Encapsulates an action as an object.

```text
Invoker
  ↓
Command
  ↓
Receiver
```

Useful for:

* Undo
* Redo
* Queued operations
* Remote actions

---

# 11.3 Interpreter

Defines a grammar and interprets expressions.

Examples:

* Expression evaluator
* Query language
* Rule engines

---

# 11.4 Iterator

Provides sequential access to elements without exposing collection internals.

```text
Collection
    ↓
Iterator
    ↓
next()
```

---

# 11.5 Mediator

Centralizes communication between objects.

Instead of:

```text
A ↔ B
A ↔ C
B ↔ C
```

use:

```text
A ──┐
B ──┼── Mediator
C ──┘
```

Useful for:

* Chat systems
* UI components
* Workflow coordination

---

# 11.6 Memento

Captures and restores an object's state.

Example:

```text
Editor
 ↓
Save State
 ↓
Memento
 ↓
Undo
```

---

# 11.7 Observer

One-to-many dependency.

```text
Subject
  │
  ├── Observer A
  ├── Observer B
  └── Observer C
```

Examples:

* Notifications
* Event systems
* Stock price updates
* UI state updates

---

# 11.8 State

Changes object behavior based on its internal state.

```text
VendingMachine
      ↓
 ┌────┼────────┐
 ↓    ↓        ↓
Idle  Selected  Dispensing
```

---

# 11.9 Strategy

Encapsulates interchangeable algorithms.

```text
PaymentService
      ↓
PaymentStrategy
 ┌────┼──────┐
 ↓    ↓      ↓
Card UPI    Cash
```

Examples:

* Payment
* Pricing
* Routing
* Compression
* Sorting

---

# 11.10 Template Method

Defines the skeleton of an algorithm while allowing subclasses to customize specific steps.

```text
process()
 ├── validate()
 ├── execute()
 └── finish()
```

---

# 11.11 Visitor

Allows adding operations to object structures without modifying the classes.

Useful for:

* AST
* Compilers
* Document processing

---

# 12. Enterprise/Application Patterns

These patterns are extremely useful in production applications.

---

## Repository Pattern

Separates business logic from data access.

```text
Service
   ↓
Repository
   ↓
Database
```

---

## Service Layer

Contains business operations.

```text
Controller
    ↓
Service
    ↓
Repository
```

---

## DAO

Data Access Object.

Provides an abstraction over database access.

---

## DTO

Data Transfer Object.

Used to transfer data between layers or services.

```text
Request DTO
Response DTO
```

---

## Unit of Work

Coordinates multiple database operations as one logical transaction.

---

## Specification Pattern

Encapsulates business rules or query criteria.

```text
Specification
      ↓
isSatisfiedBy()
```

---

## Data Mapper

Separates domain objects from persistence objects.

```text
Domain Object
      ↕
Data Mapper
      ↕
Database Model
```

---

## Active Record

Object contains both:

```text
Data
+
Database Operations
```

---

## Identity Map

Ensures the same database entity is represented by one in-memory object within a context.

---

## Lazy Loading

Loads data only when it is actually needed.

---

## Identity Field

Object contains an identifier corresponding to a database record.

---

## Service Locator

Provides dependencies through a central registry.

Generally, explicit Dependency Injection is preferred because Service Locator can hide dependencies.

---

# 13. Concurrency Patterns

Concurrency becomes important when multiple threads/tasks operate simultaneously.

---

## Thread Pool

Reuse a fixed number of worker threads.

```text
Tasks
 ↓
Thread Pool
 ├── Thread 1
 ├── Thread 2
 ├── Thread 3
 └── Thread 4
```

---

## Producer-Consumer

```text
Producer
   ↓
Queue
   ↓
Consumer
```

Useful for:

* Background jobs
* Message processing
* Task systems

---

## Object Pool

Reuse expensive objects.

Examples:

* Database connections
* Threads
* Network connections

---

## Read-Write Lock

Allows:

```text
Multiple Readers
```

but restricts:

```text
Writer
```

---

## Immutable Object

State cannot change after creation.

Benefits:

* Thread safety
* Predictability
* Easier testing

---

## Monitor Object

Synchronizes access to shared resources.

---

## Double-Checked Locking

Used in some lazy singleton implementations.

Must be implemented carefully according to the language's memory model.

---

## Future / Promise

Represents a result that will become available later.

---

## Semaphore

Controls how many threads can access a resource simultaneously.

---

## Barrier

Allows multiple threads to wait until all participants reach a synchronization point.

---

## Actor Model

Objects communicate through asynchronous messages instead of directly sharing mutable state.

---

# 14. Distributed System Patterns

These are useful when LLD extends into distributed production systems.

---

# 14.1 Retry Pattern

Retry failed operations.

```text
Request
 ↓
Failure
 ↓
Retry
 ↓
Success
```

Use:

* Exponential backoff
* Jitter
* Maximum retry count

---

# 14.2 Timeout Pattern

Never allow requests to wait indefinitely.

```text
Request
 ↓
Timeout
 ↓
Failure/Fallback
```

---

# 14.3 Circuit Breaker

Protects systems from cascading failures.

```text
CLOSED
  ↓
OPEN
  ↓
HALF-OPEN
  ↓
CLOSED
```

---

# 14.4 Bulkhead

Isolates resources so one failure does not consume everything.

```text
Service
 ├── Pool A
 ├── Pool B
 └── Pool C
```

---

# 14.5 Rate Limiter

Controls request frequency.

Algorithms:

* Fixed Window
* Sliding Window
* Sliding Window Log
* Token Bucket
* Leaky Bucket

---

# 14.6 Idempotency

Repeated execution produces the same intended result.

Critical for:

* Payments
* Orders
* APIs
* Message processing

Example:

```text
Idempotency-Key: payment-123
```

---

# 14.7 Saga Pattern

Manages distributed transactions using a sequence of local transactions.

```text
Order
 ↓
Payment
 ↓
Inventory
 ↓
Shipping
```

If something fails:

```text
Compensating Transaction
```

---

# 14.8 Outbox Pattern

Stores an event and database change reliably.

```text
Application
   ↓
Database
 ├── Business Data
 └── Outbox Event
        ↓
    Event Publisher
        ↓
      Kafka
```

---

# 14.9 CQRS

Separates:

```text
Command → Write
Query   → Read
```

---

# 14.10 Event Sourcing

Stores state changes as events.

```text
Event 1
Event 2
Event 3
Event 4
   ↓
Current State
```

---

# 14.11 Distributed Lock

Ensures only one process performs a critical operation.

Use cases:

* Inventory reservation
* Scheduled jobs
* Leader election
* Duplicate prevention

---

# 14.12 Consistent Hashing

Maps objects to nodes while minimizing reassignment when nodes change.

Useful for:

* Distributed caches
* Sharding
* Load distribution

---

# 15. Dependency Injection

Instead of:

```text
class OrderService {
    Database db = new MySQLDatabase();
}
```

prefer:

```text
class OrderService {
    Database db;

    OrderService(Database db) {
        this.db = db;
    }
}
```

Now:

```text
OrderService
      ↓
Database Interface
      ↑
 ┌────┴─────┐
MySQL     MongoDB
```

Benefits:

* Testability
* Loose coupling
* Flexibility
* Maintainability

---

# 16. Layered Architecture

A common LLD structure:

```text
┌────────────────────┐
│    Controller      │
├────────────────────┤
│      Service       │
├────────────────────┤
│    Repository      │
├────────────────────┤
│     Database       │
└────────────────────┘
```

### Controller

Handles input/output.

### Service

Contains business logic.

### Repository

Handles data access.

### Database

Stores persistent data.

---

# 17. Clean Architecture

A typical structure:

```text
        ┌───────────────────┐
        │   Presentation    │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │     Use Cases     │
        └─────────┬─────────┘
                  ↓
        ┌───────────────────┐
        │      Domain       │
        └─────────┬─────────┘
                  ↑
        ┌───────────────────┐
        │ Infrastructure    │
        └───────────────────┘
```

The domain should remain independent of infrastructure details.

---

# 18. Domain-Driven Design Basics

Important concepts:

* Domain
* Entity
* Value Object
* Aggregate
* Aggregate Root
* Repository
* Domain Service
* Application Service
* Domain Event
* Bounded Context
* Ubiquitous Language

---

## Entity

Has identity.

```text
User(id=123)
```

---

## Value Object

Defined by its value rather than identity.

```text
Money(100, USD)
Address(...)
```

---

## Aggregate

Cluster of related domain objects.

```text
Order
 ├── OrderItem
 ├── Payment
 └── Address
```

---

## Aggregate Root

Entry point for modifying the aggregate.

```text
Order
 ↓
OrderItem
```

---

## Domain Event

Represents something meaningful that happened.

```text
OrderPlaced
PaymentCompleted
UserRegistered
```

---

# 19. LLD Design Process

Follow this process for every LLD problem.

```text
1. Understand Requirements
        ↓
2. Identify Actors
        ↓
3. Identify Use Cases
        ↓
4. Identify Entities
        ↓
5. Identify Responsibilities
        ↓
6. Identify Relationships
        ↓
7. Define Interfaces
        ↓
8. Apply SOLID
        ↓
9. Identify Design Patterns
        ↓
10. Create UML
        ↓
11. Implement
        ↓
12. Handle Edge Cases
        ↓
13. Add Tests
        ↓
14. Review Extensibility
```

---

# 20. LLD Problem-Solving Framework

For every problem ask:

### Step 1 — What are the requirements?

Example:

```text
Parking Lot

- Multiple floors
- Multiple vehicle types
- Multiple parking spot types
- Entry gate
- Exit gate
- Ticket
- Payment
```

---

### Step 2 — Identify actors

```text
Customer
Admin
Parking Attendant
Payment System
```

---

### Step 3 — Identify entities

```text
Vehicle
ParkingLot
ParkingFloor
ParkingSpot
Ticket
Payment
Gate
```

---

### Step 4 — Identify behavior

Ask:

> What can each object do?

---

### Step 5 — Identify what changes

Changing behavior is a strong signal for Strategy, State, Factory, etc.

---

### Step 6 — Apply SOLID

Check:

```text
SRP?
OCP?
LSP?
ISP?
DIP?
```

---

### Step 7 — Select patterns

Do not force patterns.

Use a pattern only when it solves an actual design problem.

---

# 21. LLD Case Studies

Practice these problems.

---

# Beginner

* [ ] Tic-Tac-Toe
* [ ] Snake & Ladder
* [ ] Parking Lot
* [ ] Library Management
* [ ] Vending Machine
* [ ] ATM
* [ ] Car Rental
* [ ] Movie Ticket Booking

---

# Intermediate

* [ ] Elevator System
* [ ] Splitwise
* [ ] Chess
* [ ] Hotel Booking
* [ ] Cab Booking
* [ ] Food Delivery
* [ ] Notification System
* [ ] Logging Framework
* [ ] File System
* [ ] Rate Limiter
* [ ] Cache

---

# Advanced

* [ ] Payment Gateway
* [ ] Inventory Management
* [ ] Stock Exchange
* [ ] Meeting Scheduler
* [ ] Ride Sharing
* [ ] Workflow Engine
* [ ] Distributed Task Scheduler
* [ ] E-commerce Order System
* [ ] Ticket Reservation System
* [ ] Real-Time Notification Platform

---

# 22. Pattern Mapping

Understanding which pattern fits which problem is more important than memorizing definitions.

| Problem           | Patterns                                |
| ----------------- | --------------------------------------- |
| Parking Lot       | Factory, Strategy                       |
| Vending Machine   | State, Factory                          |
| ATM               | State, Chain of Responsibility          |
| Elevator          | State, Strategy, Observer               |
| Chess             | Strategy, Factory, Command              |
| Tic-Tac-Toe       | Strategy                                |
| Snake & Ladder    | Factory, Strategy                       |
| Splitwise         | Strategy                                |
| Notification      | Observer, Strategy, Factory             |
| Payment           | Strategy, Factory, Adapter              |
| Food Delivery     | Observer, State, Strategy               |
| Cab Booking       | Strategy, Observer, State               |
| Movie Booking     | State, Strategy                         |
| Hotel Booking     | State, Strategy                         |
| File System       | Composite, Iterator                     |
| Logger            | Singleton, Chain of Responsibility      |
| Coffee Machine    | Decorator, Factory                      |
| Remote Control    | Command                                 |
| Stock Market      | Observer, Strategy                      |
| Meeting Scheduler | Strategy                                |
| Cache             | Strategy, Factory                       |
| Rate Limiter      | Strategy                                |
| Workflow Engine   | State, Command, Chain of Responsibility |

---

# 23. Concurrency & Thread Safety

For every shared resource ask:

```text
Can multiple threads access it?
        ↓
Yes
        ↓
Is the state mutable?
        ↓
Yes
        ↓
How will access be synchronized?
```

Learn:

* Race condition
* Deadlock
* Starvation
* Mutex
* Semaphore
* Read-write lock
* Atomic operations
* Thread-safe collections
* Immutable objects
* Thread pools
* Connection pools
* Producer-consumer

---

# 24. Error Handling

Good LLD should define how failures are handled.

Consider:

* Validation errors
* Business exceptions
* Infrastructure failures
* Network failures
* Database failures
* Timeout
* Retry
* Fallback
* Logging
* Error response

Example:

```text
Controller
    ↓
Service
    ↓
Exception
    ↓
Global Error Handler
    ↓
Standard Error Response
```

---

# 25. Testing LLD

Every LLD implementation should consider:

## Unit Testing

Test individual classes.

```text
PaymentService
    ↓
Unit Tests
```

---

## Integration Testing

Test multiple components together.

```text
Service
 ↓
Repository
 ↓
Database
```

---

## Mocking

Replace real dependencies during tests.

```text
OrderService
      ↓
MockRepository
```

---

## Test Design

Test:

* Happy path
* Edge cases
* Invalid input
* Null values
* Exceptions
* Concurrent access
* Failure scenarios
* Boundary conditions

---

# 26. Code Quality

A good LLD should be:

```text
Readable
Maintainable
Testable
Extensible
Reusable
Loosely Coupled
Highly Cohesive
```

Avoid:

* God classes
* God methods
* Deep inheritance
* Circular dependencies
* Tight coupling
* Duplicate code
* Hidden dependencies
* Premature abstraction
* Pattern overuse

---

# 27. LLD Interview Preparation

For an LLD interview, be prepared to answer:

### OOP

* What is encapsulation?
* What is abstraction?
* Composition vs inheritance?
* Overloading vs overriding?
* Interface vs abstract class?
* What is polymorphism?

### SOLID

* Explain all SOLID principles.
* Give a real-world example of SRP.
* How does Strategy help OCP?
* Explain LSP violation.
* Why is DIP important?

### Design Patterns

* What problem does Factory solve?
* Factory vs Abstract Factory?
* Builder vs Factory?
* Strategy vs State?
* Adapter vs Facade?
* Decorator vs Proxy?
* Observer vs Mediator?
* Command vs Strategy?
* Composite vs Decorator?
* Singleton disadvantages?

### Design

* Design Parking Lot.
* Design Elevator.
* Design ATM.
* Design Vending Machine.
* Design Splitwise.
* Design Chess.
* Design Notification System.
* Design Payment System.
* Design Cab Booking.
* Design File System.

---

# 28. Complete Learning Checklist

## OOP

* [ ] Class
* [ ] Object
* [ ] Encapsulation
* [ ] Abstraction
* [ ] Inheritance
* [ ] Polymorphism
* [ ] Composition
* [ ] Aggregation
* [ ] Association

---

## SOLID

* [ ] SRP
* [ ] OCP
* [ ] LSP
* [ ] ISP
* [ ] DIP

---

## Design Principles

* [ ] DRY
* [ ] KISS
* [ ] YAGNI
* [ ] Separation of Concerns
* [ ] Composition over Inheritance
* [ ] Encapsulate What Varies
* [ ] Program to an Interface
* [ ] Law of Demeter
* [ ] Principle of Least Knowledge
* [ ] Immutability

---

## UML

* [ ] Class Diagram
* [ ] Object Diagram
* [ ] Sequence Diagram
* [ ] Use Case Diagram
* [ ] Activity Diagram
* [ ] State Diagram
* [ ] Component Diagram
* [ ] Deployment Diagram

---

# Creational Patterns

* [ ] Singleton
* [ ] Factory Method
* [ ] Abstract Factory
* [ ] Builder
* [ ] Prototype

---

# Structural Patterns

* [ ] Adapter
* [ ] Bridge
* [ ] Composite
* [ ] Decorator
* [ ] Facade
* [ ] Flyweight
* [ ] Proxy

---

# Behavioral Patterns

* [ ] Chain of Responsibility
* [ ] Command
* [ ] Interpreter
* [ ] Iterator
* [ ] Mediator
* [ ] Memento
* [ ] Observer
* [ ] State
* [ ] Strategy
* [ ] Template Method
* [ ] Visitor

---

# Enterprise Patterns

* [ ] Repository
* [ ] DAO
* [ ] DTO
* [ ] Service Layer
* [ ] Unit of Work
* [ ] Specification
* [ ] Data Mapper
* [ ] Active Record
* [ ] Identity Map
* [ ] Lazy Loading
* [ ] Identity Field
* [ ] Service Locator

---

# Concurrency Patterns

* [ ] Thread Pool
* [ ] Producer-Consumer
* [ ] Object Pool
* [ ] Read-Write Lock
* [ ] Immutable Object
* [ ] Monitor Object
* [ ] Future/Promise
* [ ] Semaphore
* [ ] Barrier
* [ ] Actor Model
* [ ] Double-Checked Locking

---

# Distributed Patterns

* [ ] Retry
* [ ] Timeout
* [ ] Exponential Backoff
* [ ] Circuit Breaker
* [ ] Bulkhead
* [ ] Rate Limiter
* [ ] Idempotency
* [ ] Saga
* [ ] Outbox
* [ ] CQRS
* [ ] Event Sourcing
* [ ] Distributed Lock
* [ ] Consistent Hashing

---

# Architecture

* [ ] Layered Architecture
* [ ] MVC
* [ ] MVP
* [ ] MVVM
* [ ] Repository Architecture
* [ ] Clean Architecture
* [ ] Hexagonal Architecture
* [ ] Onion Architecture

---

# Domain-Driven Design

* [ ] Entity
* [ ] Value Object
* [ ] Aggregate
* [ ] Aggregate Root
* [ ] Domain Service
* [ ] Application Service
* [ ] Repository
* [ ] Domain Event
* [ ] Bounded Context
* [ ] Ubiquitous Language

---

# LLD Problems

* [ ] Parking Lot
* [ ] Vending Machine
* [ ] ATM
* [ ] Elevator
* [ ] Chess
* [ ] Tic-Tac-Toe
* [ ] Snake & Ladder
* [ ] Splitwise
* [ ] Cab Booking
* [ ] Food Delivery
* [ ] Movie Booking
* [ ] Hotel Booking
* [ ] Notification System
* [ ] Payment System
* [ ] File System
* [ ] Logger
* [ ] Cache
* [ ] Rate Limiter
* [ ] Meeting Scheduler
* [ ] Inventory System
* [ ] Workflow Engine
* [ ] Stock Exchange

---

# 🏆 The LLD Mastery Path

Follow this order:

```text
                 OOP
                  ↓
              SOLID
                  ↓
        Design Principles
                  ↓
                 UML
                  ↓
       ┌──────────┴──────────┐
       ↓                     ↓
 Creational              Structural
       ↓                     ↓
       └──────────┬──────────┘
                  ↓
              Behavioral
                  ↓
          Enterprise Patterns
                  ↓
         Concurrency Patterns
                  ↓
        Distributed Patterns
                  ↓
        Architecture Patterns
                  ↓
          LLD Case Studies
                  ↓
             Real Code
                  ↓
             Unit Tests
                  ↓
          Production LLD
```

---

# ⭐ Golden Rules of LLD

### Rule 1

> Don't use a design pattern just because you know it.

### Rule 2

> First understand the problem, then identify the changing behavior.

### Rule 3

> Prefer composition over inheritance.

### Rule 4

> Depend on abstractions rather than concrete implementations.

### Rule 5

> Keep classes small and focused.

### Rule 6

> Keep coupling low and cohesion high.

### Rule 7

> Design for change, but don't over-engineer.

### Rule 8

> Make dependencies explicit.

### Rule 9

> Think about concurrency when shared mutable state exists.

### Rule 10

> Every design decision should have a reason.

---

# 🚀 Final LLD Goal

After completing this guide, you should be able to take a problem such as:

> **"Design a Parking Lot."**

and systematically move from:

```text
Requirements
      ↓
Actors
      ↓
Use Cases
      ↓
Entities
      ↓
Responsibilities
      ↓
Classes
      ↓
Interfaces
      ↓
Relationships
      ↓
SOLID
      ↓
Design Patterns
      ↓
UML
      ↓
Implementation
      ↓
Testing
      ↓
Concurrency
      ↓
Extensibility
```

The goal of LLD is **not to memorize 23 patterns**.

The real goal is:

```text
Understand the Problem
        +
Identify Responsibilities
        +
Control Dependencies
        +
Encapsulate What Changes
        +
Apply Appropriate Patterns
        +
Design for Extensibility
        +
Write Maintainable Code
```

---

# 🌟 LLD Philosophy

> **Good LLD is not about writing more classes.
> Good LLD is about giving every class the right responsibility.**

```text
Low Coupling
     +
High Cohesion
     +
SOLID
     +
Appropriate Patterns
     +
Clear Abstractions
     +
Testability
     =
Strong LLD
```

---

## 📌 Recommended Repository Name

For the complete project, use:

# `SystemDesign-Playbook`

Suggested structure:

```text
SystemDesign-Playbook/
│
├── 01-Fundamentals/
├── 02-UML/
├── 03-LLD/
│   └── README.md
├── 04-Design-Patterns/
├── 05-HLD/
├── 06-Distributed-Systems/
├── 07-Databases/
├── 08-Caching/
├── 09-Messaging/
├── 10-Microservices/
├── 11-Cloud/
├── 12-Observability/
├── 13-AI-System-Design/
└── 14-Interview-Preparation/
```

**Recommended LLD path:**

```text
OOP
 ↓
SOLID
 ↓
Design Principles
 ↓
UML
 ↓
23 GoF Patterns
 ↓
Enterprise Patterns
 ↓
Concurrency Patterns
 ↓
Distributed Patterns
 ↓
Clean Architecture
 ↓
DDD
 ↓
LLD Problems
 ↓
Production-Grade LLD
```
