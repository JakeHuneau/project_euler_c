run PROBLEM_NUMBER:
    gcc -std=c23 src/{{PROBLEM_NUMBER}}.c src/util.c src/prime.c src/bignum.c -lm -I./include -o bin/{{PROBLEM_NUMBER}} && ./bin/{{PROBLEM_NUMBER}}
        
