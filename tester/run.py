"""
EPITECH PROJECT, 2025
Corewar
File description:
Return value tester
"""

import subprocess

tests_mine = [
    ["./corewar", ""],
    ["./corewar", "-dump"],
    ["./corewar", "-n"],
    ["./corewar", "-a"],
    ["./corewar", "-dump", "examples/champions/abel.cor"],
    ["./corewar", "-n", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "-1", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "abc", "examples/champions/abel.cor"],
    ["./corewar", "-n", "-5", "examples/champions/abel.cor"],
    ["./corewar", "-n", "abc", "examples/champions/abel.cor"],
    ["./corewar", "-a", "-10", "examples/champions/abel.cor"],
    ["./corewar", "-a", "xyz", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "2147483647", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "999999999999", "examples/champions/abel.cor"],
    ["./corewar", "-n", "0", "examples/champions/abel.cor"],
    ["./corewar", "-a", "0", "examples/champions/abel.cor"],
    ["./corewar", "examples/champions/abel.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor", "examples/champions/tyron.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "0", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "0", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./corewar", "-dump", "0", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor"],
    ["./corewar", "-dump", "0", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor", "examples/champions/tyron.cor"],
    ["./corewar", "examples/champions/abel.cor", "-dump", "0"],
    ["./corewar", "-dump", "0"],
    ["./corewar", "-dump", "0", "examples/champions/abel.cor", "-dump", "0"],
    ["./corewar", "examples/champions/abel.cor", "-dump", "0"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0", "examples/champions/pdd.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0", "-dump", "0"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0", "-dump", "100"],
    ["./corewar", "-n", "4", "examples/champions/abel.cor", "-n", "3", "examples/champions/bill.cor", "-n", "2", "examples/champions/pdd.cor", "-n", "1", "examples/champions/tyron.cor"],
    ["./corewar", "-n", "4", "examples/champions/abel.cor", "-n", "3", "examples/champions/bill.cor", "-n", "2", "examples/champions/pdd.cor", "-n", "1", "examples/champions/tyron.cor", "-dump", "0"],
    ["./corewar", "-dump", "0", "-n", "4", "examples/champions/abel.cor", "-n", "3", "examples/champions/bill.cor", "-n", "2", "examples/champions/pdd.cor", "-n", "1", "examples/champions/tyron.cor"],
    ["./corewar", "-dump", "-n", "0", "4", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./corewar", "-dump", "10", "-dump", "20", "examples/champions/abel.cor"],
    ["./corewar", "-n", "1", "-n", "1", "examples/champions/abel.cor"],
    ["./corewar", "-a", "100", "-a", "200", "examples/champions/abel.cor"],
    ["./corewar", "-n", "1", "examples/champions/abel.cor", "-a", "100", "examples/champions/bill.cor"],
    ["./corewar", "examples/champions/abel.cor", "-n", "2", "examples/champions/bill.cor", "-a", "200"],
    ["./corewar", "-a", "100", "examples/champions/abel.cor", "-n", "2", "examples/champions/bill.cor"],
    ["./corewar", "-dump", "10"],
    ["./corewar", "fake.cor"],
    ["./corewar", "examples/champions/abel.cor", "not_existing.cor"],
    ["./corewar", "   ", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "50", "-n", "1", "examples/champions/abel.cor", "-a", "100", "-n", "2", "examples/champions/bill.cor"],
    ["./corewar", "-n", "1", "-a", "100", "examples/champions/abel.cor", "-n", "1", "examples/champions/bill.cor"],
    ["./corewar", "-a", "100", "-a", "200", "examples/champions/abel.cor"],
    ["./corewar", "-n", "1", "examples/champions/abel.cor", "-dump", "100", "-n", "2", "examples/champions/bill.cor"],
]

tests_ref = [
    ["./examples/binaries/corewar", ""],
    ["./examples/binaries/corewar", "-dump"],
    ["./examples/binaries/corewar", "-n"],
    ["./examples/binaries/corewar", "-a"],
    ["./examples/binaries/corewar", "-dump", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "-1", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "abc", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "-5", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "abc", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-a", "-10", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-a", "xyz", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "2147483647", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "999999999999", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "0", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-a", "0", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor", "examples/champions/tyron.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "0", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "0", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "-dump", "0", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor"],
    ["./examples/binaries/corewar", "-dump", "0", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor", "examples/champions/tyron.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "-dump", "0"],
    ["./examples/binaries/corewar", "-dump", "0"],
    ["./examples/binaries/corewar", "-dump", "0", "examples/champions/abel.cor", "-dump", "0"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "-dump", "0"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0", "examples/champions/pdd.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0", "-dump", "0"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "-dump", "0", "-dump", "100"],
    ["./examples/binaries/corewar", "-n", "4", "examples/champions/abel.cor", "-n", "3", "examples/champions/bill.cor", "-n", "2", "examples/champions/pdd.cor", "-n", "1", "examples/champions/tyron.cor"],
    ["./examples/binaries/corewar", "-n", "4", "examples/champions/abel.cor", "-n", "3", "examples/champions/bill.cor", "-n", "2", "examples/champions/pdd.cor", "-n", "1", "examples/champions/tyron.cor", "-dump", "0"],
    ["./examples/binaries/corewar", "-dump", "0", "-n", "4", "examples/champions/abel.cor", "-n", "3", "examples/champions/bill.cor", "-n", "2", "examples/champions/pdd.cor", "-n", "1", "examples/champions/tyron.cor"],
    ["./examples/binaries/corewar", "-dump", "-n", "0", "4", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "-dump", "10", "-dump", "20", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "1", "-n", "1", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-a", "100", "-a", "200", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "1", "examples/champions/abel.cor", "-a", "100", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "-n", "2", "examples/champions/bill.cor", "-a", "200"],
    ["./examples/binaries/corewar", "-a", "100", "examples/champions/abel.cor", "-n", "2", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "-dump", "10"],
    ["./examples/binaries/corewar", "fake.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "not_existing.cor"],
    ["./examples/binaries/corewar", "   ", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "50", "-n", "1", "examples/champions/abel.cor", "-a", "100", "-n", "2", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "-n", "1", "-a", "100", "examples/champions/abel.cor", "-n", "1", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "-a", "100", "-a", "200", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-n", "1", "examples/champions/abel.cor", "-dump", "100", "-n", "2", "examples/champions/bill.cor"],
]

nb_tests = len(tests_mine)
nb_tests_failed = 0

for test in tests_mine:
    ref = subprocess.run(
        tests_ref[tests_mine.index(test)],
        capture_output=True,
        text=True
    )
    mine = subprocess.run(
        tests_mine[tests_mine.index(test)],
        capture_output=True,
        text=True
    )
    ok = (
        ref.returncode == mine.returncode
    )
    if not ok:
        print(f'TEST FAILED : {test}')
        print("REF RETURN VALUE :", ref.returncode)
        print("MY  RETURN VALUE :", mine.returncode)
        print("MY  STDOUT       :\n", mine.stderr)
        print('\n')
        nb_tests_failed += 1

print(f'\n\033[0;31mFAILED: {nb_tests_failed} \033[0;32mPASSED: {nb_tests - nb_tests_failed} \033[0;37mCOVERAGE: {100 - (nb_tests_failed / nb_tests * 100):.2f}%')