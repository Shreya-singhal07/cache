# project-work
Demonstrating caching algorithms
<br>

![example workflow](https://github.com/github/docs/actions/workflows/main.yml/badge.svg)
![main](https://github.com/github/docs/actions/workflows/main.yml/badge.svg) <br>
## Why

<br> **learning software development life cycle** </br>
  > requirement collections, 
  > designing, 
  > coding, 
  > unit testing
  
<br> **learning how caching algorithm works** </br>
<br> **learning how to write modular code** </br>

## Features

**eviction policy** : algorithm which determines which element is removed incase my capacity of the cache is exceeded.

## learnings

- [x] cache and it's internal implementation
- [x] eviction policy and it's application in real life
- [x] how to come up with optimised version from high time complexity code
- [x] how classes are imlpemented and it's importance

## DAY 1

<img width="351" alt="image" src="https://user-images.githubusercontent.com/69424250/207519263-f89dac34-8764-4761-ba81-e8b5438cb7e8.png"> <img width="243" alt="image" src="https://user-images.githubusercontent.com/69424250/207519329-18b74796-c43f-43a7-a5bb-10d47286f3ec.png">
<img width="903" alt="image" src="https://user-images.githubusercontent.com/69424250/207519589-2ce21453-cadc-428d-ad5e-a36bea523d94.png">


## DAY 2

- [x] added Base Class CACHE
- [x] added Derived Class MinimumKeyRemovePolicyCache
- [x] added Derived Class MaximumKeyRemovePolicyCache

## DAY 3

> brute force - LRU Cache
> TC: **O(capacity)**
> Data Structure : VECTOR

<img width="343" alt="image" src="https://user-images.githubusercontent.com/69424250/208149079-fdf9c0a9-8fa3-4651-a67c-2bbcbc28636d.png">

## DAY 4

**example:**
<img width="600" alt="Screenshot 2022-12-24 at 11 32 16 PM" src="https://user-images.githubusercontent.com/69424250/209446959-fea1952a-dcba-46bc-8141-c8a967e2da59.png">


## DAY 5
<br>optimised code</br>


<img width="500" alt="image" src="https://user-images.githubusercontent.com/69424250/209698938-1145600a-2925-4767-a936-88e9c7d321b4.png"> <img width="500" alt="image" src="https://user-images.githubusercontent.com/69424250/209696239-e9a42dd2-d2cc-43a2-899e-f30201497027.png">
<img width="600" alt="image" src="https://user-images.githubusercontent.com/69424250/209711709-5a010097-0e91-4ad0-8892-383239fab24e.png"> <img width="400" height ="320" alt="image" src="https://user-images.githubusercontent.com/69424250/209711619-54c6929b-7010-4e9c-9023-c2a2216e966b.png">


## DAY 6
compiling and running rest cases :)

<img width="600" alt="image" src="https://user-images.githubusercontent.com/69424250/209710448-542cae60-5f3b-4cba-8749-eba31d1d9e25.png">


## Challenges⚡️

- [x] making sure current functionality doesn't break while adding new features (solution : testing and different testcases in the following push commands)
- [x] avoiding repeated code (solution : analyse and create a single function for common feature)
- [x] working on time complexity for put function [ O(n) to O(log n) ]

