run PROBLEM_NUMBER:
    gcc -std=c23 src/{{PROBLEM_NUMBER}}.c src/util.c src/prime.c src/bignum.c -lm -I./include -o bin/{{PROBLEM_NUMBER}} && ./bin/{{PROBLEM_NUMBER}}

test:
    for f in `ls bin/*`; do \
        echo "Testing $f..."; \
        $f && echo "✅ $f passed" || echo "❌ $f failed"; \
    done
