run PROBLEM_NUMBER:
    gcc -std=c23 src/{{PROBLEM_NUMBER}}.c src/util.c -lm -I./include -o bin/{{PROBLEM_NUMBER}} && ./bin/{{PROBLEM_NUMBER}}
        
