<h1 align="center">Welcome to Push_swap_42 👋</h1>
<p>
  <img alt="Version" src="https://img.shields.io/badge/version-1.0-blue.svg?cacheSeconds=2592000" />
  </a>
</p>

<h1>What is Push_swap ?</h1> 

<p>

* This project will make sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
* This projec contains 2 programs : 
  * The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
  * The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.
</p>


| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |



## Install

```sh
make
```

## Usage

```sh
./push_swap [list of integers]

./checker [list of integers] and [list of instructions]

./push_swap [list of integers] | ./checker [same list of integers]
```

You can also user $ARG env variable : 

```sh

ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

./push_swap $ARG

./checker $ARG and [list of instructions]

./push_swap $ARG | ./checker $ARG
```

## Run tests

In other directory :

```sh
./check.sh
```

For python visu : 


```sh

python3 visu.py [list of integers]

Example : 

python3 visu.py 71 27 17 8 98 85 13 94 5 16 58 10 72 18 1 26 9 57 89 39 50 82 59 12 52 60 55 81

```

## Authors

👤 **Charles**

* GitHub: [@charlesctr](https://github.com/charlesctr)

## 📝 License

Copyright © 2020 [Charles Ctr] (https://github.com/charlesctr).<br />
***
