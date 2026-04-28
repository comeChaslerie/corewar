"""
EPITECH PROJECT, 2025
Corewar
File description:
Return value tester
"""

import subprocess

tests_mine = [
    ["./corewar", ""],
    ["./corewar", "examples/champions/abel.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor", "examples/champions/tyron.cor"],
    ["./corewar", "examples/champions/abel.cor", "examples/champions/abel.cor"],
    ["./corewar", "-dump", "0", "examples/champions/abel.cor"],
]

tests_ref = [
    ["./examples/binaries/corewar", ""],
    ["./examples/binaries/corewar", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/bill.cor", "examples/champions/pdd.cor", "examples/champions/tyron.cor"],
    ["./examples/binaries/corewar", "examples/champions/abel.cor", "examples/champions/abel.cor"],
    ["./examples/binaries/corewar", "-dump", "0", "examples/champions/abel.cor"],
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
        print('\n')
        nb_tests_failed += 1

print(f'\n\033[0;31mFAILED: {nb_tests_failed} \033[0;32mPASSED: {nb_tests - nb_tests_failed} \033[0;37mCOVERAGE: {100 - (nb_tests_failed / nb_tests * 100):.2f}%')