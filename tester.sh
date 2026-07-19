#!/bin/bash

# Configuration
SMALL_TESTS_PER_STRATEGY= 250
STRATEGIES=("--simple" "--medium" "--complex" "")
LARGE_TESTS=2500
LARGE_SIZE=500

# New Configuration Blocks
EDGE_TESTS=500
MEDIUM_LARGE_TESTS=2500

TOTAL_PASSED=0
TOTAL_FAILED=0

# Ensure binaries exist
if [ ! -f "./push_swap" ]; then
    echo -e "\033[0;31mError: ./push_swap binary not found! Please compile first.\033[0m"
    exit 1
fi

echo "=================================================="
echo "          PUSH_SWAP AUTOMATED TESTER              "
echo "=================================================="

# ==============================================================================
# SECTION 1: EDGE CASES (SIZES 0 TO 3) - 20 TESTS
# ==============================================================================
echo -e "\n\033[1;35m>>> SECTION 1: EDGE CASES (SIZES 0 TO 3) <<<\033[0m"
echo "--------------------------------------------------"

edge_passed=0
for ((i=1; i<=EDGE_TESTS; i++)); do
    # Generate size between 0 and 3
    SIZE=$(( RANDOM % 4 ))
    
    ARG=$(awk -v size="$SIZE" 'BEGIN {
        srand();
        count = 0;
        while (count < size) {
            num = int((rand() * 100) - 50);
            if (!(num in picked)) {
                picked[num] = 1;
                count++;
                printf "%d ", num;
            }
        }
    }')
    ARG=$(echo "$ARG" | xargs)
    
    OPS=$(./push_swap $ARG 2>/dev/null)
    OP_COUNT=$(echo "$OPS" | grep -v '^$' | wc -l)
    CHECKER_RESULT=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)
    
    # Special rule: If size is 0, push_swap shouldn't output anything, checker handles it safely
    if [ "$CHECKER_RESULT" == "OK" ] || { [ -z "$ARG" ] && [ -z "$OPS" ]; }; then
        echo -e "  [Edge Test $i/$EDGE_TESTS] Size $SIZE: \033[0;32mOK\033[0m ($OP_COUNT ops)"
        ((edge_passed++))
        ((TOTAL_PASSED++))
    else
        echo -e "  [Edge Test $i/$EDGE_TESTS] Size $SIZE: \033[0;31mKO / Error\033[0m -> ARG=\"$ARG\""
        echo "  Executed: ./push_swap \$ARG"
        ((TOTAL_FAILED++))
    fi
done

# ==============================================================================
# SECTION 2: SMALL STACK TESTING (SIZES 4 & 5) - 100 TESTS total
# ==============================================================================
echo -e "\n\033[1;35m>>> SECTION 2: SMALL STACK TESTING (SIZES 4 & 5) <<<\033[0m"

for strategy in "${STRATEGIES[@]}"; do
    if [ -z "$strategy" ]; then
        DISPLAY_NAME="Adaptive (No Flag)"
    else
        DISPLAY_NAME="$strategy"
    fi

    echo -e "\nRunning $SMALL_TESTS_PER_STRATEGY tests for strategy: \033[1;34m$DISPLAY_NAME\033[0m"
    echo "--------------------------------------------------"
    
    strategy_passed=0
    for ((i=1; i<=SMALL_TESTS_PER_STRATEGY; i++)); do
        SIZE=$(( (RANDOM % 2) + 4 ))
        
        ARG=$(awk -v size="$SIZE" 'BEGIN {
            srand();
            count = 0;
            while (count < size) {
                num = int((rand() * 2000) - 1000);
                if (!(num in picked)) {
                    picked[num] = 1;
                    count++;
                    printf "%d ", num;
                }
            }
        }')
        ARG=$(echo "$ARG" | xargs)
        
        if [ -z "$strategy" ]; then
            OPS=$(./push_swap $ARG 2>/dev/null)
            DISPLAY_CMD="./push_swap \$ARG"
        else
            OPS=$(./push_swap $strategy $ARG 2>/dev/null)
            DISPLAY_CMD="./push_swap $strategy \$ARG"
        fi
        
        OP_COUNT=$(echo "$OPS" | grep -v '^$' | wc -l)
        if [ -z "$strategy" ]; then
            CHECKER_RESULT=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)
        else
            CHECKER_RESULT=$(./push_swap $strategy $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)
        fi
        
        if [ "$CHECKER_RESULT" == "OK" ]; then
            echo -e "  [Test $i/$SMALL_TESTS_PER_STRATEGY] Size $SIZE: \033[0;32mOK\033[0m ($OP_COUNT ops)"
            ((strategy_passed++))
            ((TOTAL_PASSED++))
        else
            echo -e "  [Test $i/$SMALL_TESTS_PER_STRATEGY] Size $SIZE: \033[0;31mKO / Error\033[0m -> ARG=\"$ARG\""
            echo "  Executed: $DISPLAY_CMD"
            ((TOTAL_FAILED++))
        fi
    done
done

# ==============================================================================
# SECTION 3: FIXED ADAPTIVE STRATEGY STRESS TEST (SIZE 100) - 100 TESTS
# ==============================================================================
echo -e "\n\033[1;35m>>> SECTION 3: ADAPTIVE STRATEGY STRESS TEST (SIZE 100) <<<\033[0m"
echo "--------------------------------------------------"

large_passed=0
for ((i=1; i<=LARGE_TESTS; i++)); do
    ARG=$(awk -v size="$LARGE_SIZE" 'BEGIN {
        srand();
        count = 0;
        while (count < size) {
            num = int((rand() * 100000) - 50000);
            if (!(num in picked)) {
                picked[num] = 1;
                count++;
                printf "%d ", num;
            }
        }
    }')
    ARG=$(echo "$ARG" | xargs)
    
    OPS=$(./push_swap $ARG 2>/dev/null)
    OP_COUNT=$(echo "$OPS" | grep -v '^$' | wc -l)
    CHECKER_RESULT=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)
    
    if [ "$CHECKER_RESULT" == "OK" ]; then
        ((large_passed++))
        ((TOTAL_PASSED++))
        
    if [ "$LARGE_SIZE" -gt 400 ]; then
        if [ "$OP_COUNT" -le 5500 ]; then
            PERF_RATING="\033[0;32mExcellent\033[0m"
        elif [ "$OP_COUNT" -le 8000 ]; then
            PERF_RATING="\033[0;36mGood\033[0m"
        elif [ "$OP_COUNT" -le 12000 ]; then
            PERF_RATING="\033[0;33mPass\033[0m"
        else
            PERF_RATING="\033[0;31mFail (Too many ops)\033[0m"
        fi
    else
        if [ "$OP_COUNT" -le 700 ]; then
            PERF_RATING="\033[0;32mExcellent\033[0m"
        elif [ "$OP_COUNT" -le 1500 ]; then
            PERF_RATING="\033[0;36mGood\033[0m"
        elif [ "$OP_COUNT" -le 2000 ]; then
            PERF_RATING="\033[0;33mPass\033[0m"
        else
            PERF_RATING="\033[0;31mFail (Too many ops)\033[0m"
        fi
    fi
        echo -e "  [Large Test $i/$LARGE_TESTS]: \033[0;32mOK\033[0m ($OP_COUNT ops) -> $PERF_RATING"
    else
        echo -e "  [Large Test $i/$LARGE_TESTS]: \033[0;31mKO / Error\033[0m -> ARG=\"$ARG\""
        ((TOTAL_FAILED++))
    fi
done

# ==============================================================================
# SECTION 4: MEDIUM-LARGE ADAPTIVE STRESS TEST (SIZES 100-500) - 80 TESTS
# ==============================================================================
echo -e "\n\033[1;35m>>> SECTION 4: ADAPTIVE MIXED STRESS TEST (SIZES 100 TO 500) <<<\033[0m"
echo "--------------------------------------------------"

ml_passed=0
for ((i=1; i<=MEDIUM_LARGE_TESTS; i++)); do
    # Pick a random size dynamically between 100 and 500
    SIZE=$(( RANDOM % 401 + 100 ))
    
    ARG=$(awk -v size="$SIZE" 'BEGIN {
        srand();
        count = 0;
        while (count < size) {
            num = int((rand() * 200000) - 100000);
            if (!(num in picked)) {
                picked[num] = 1;
                count++;
                printf "%d ", num;
            }
        }
    }')
    ARG=$(echo "$ARG" | xargs)
    
    OPS=$(./push_swap $ARG 2>/dev/null)
    OP_COUNT=$(echo "$OPS" | grep -v '^$' | wc -l)
    CHECKER_RESULT=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)
    
    if [ "$CHECKER_RESULT" == "OK" ]; then
        ((ml_passed++))
        ((TOTAL_PASSED++))
        
        # Performance metric checking limits scales lineally or targets specific max bounds
        if [ $SIZE -eq 500 ]; then
            if [ $OP_COUNT -le 5500 ]; then PERF_RATING="\033[0;32mExcellent\033[0m"
            elif [ $OP_COUNT -le 8000 ]; then PERF_RATING="\033[0;36mGood\033[0m"
            elif [ $OP_COUNT -le 12000 ]; then PERF_RATING="\033[0;33mPass\033[0m"
            else PERF_RATING="\033[0;31mFail\033[0m"; fi
        else
            PERF_RATING="\033[0;32mOK\033[0m"
        fi
        
        echo -e "  [ML Test $i/$MEDIUM_LARGE_TESTS] Size $SIZE: \033[0;32mOK\033[0m ($OP_COUNT ops) -> $PERF_RATING"
    else
        echo -e "  [ML Test $i/$MEDIUM_LARGE_TESTS] Size $SIZE: \033[0;31mKO / Error\033[0m -> ARG=\"$ARG\""
        ((TOTAL_FAILED++))
    fi
done

# ==============================================================================
# FINAL DISPATCH LOGIC
# ==============================================================================
echo -e "\n=================================================="
echo "                FINAL SUMMARY                     "
echo "=================================================="
TOTAL_PLANNED=$((EDGE_TESTS + 100 + LARGE_TESTS + MEDIUM_LARGE_TESTS))
echo -e "Total Executed Passes: \033[1;37m$((TOTAL_PASSED + TOTAL_FAILED))\033[0m / $TOTAL_PLANNED"
echo -e "Total Successful:      \033[0;32m$TOTAL_PASSED\033[0m"
if [ $TOTAL_FAILED -gt 0 ]; then
    echo -e "Total Failures:        \033[0;31m$TOTAL_FAILED\033[0m"
    exit 1
else
    echo -e "All test profiles evaluated as \033[0;32mSUCCESSFUL\033[0m!"
    exit 0
fi
