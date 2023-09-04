import argparse
import random
import os
import logging

if __name__ == "__main__":
    argparser = argparse.ArgumentParser()
    argparser.add_argument("-n", "--number", help="Number of values")
    argparser.add_argument("-p", "--problem", help="Problem to solve, e.g. sorting")
    args = argparser.parse_args()
    
    if not (args.problem):
        logging.error("No problem requested, add --problem")
        os._exit(1)

    if (args.problem == "sorting"):
        with open("../01_Divide_And_Conquer/datos.txt", "w") as f:
            n = int(args.number)
            f.write(f"{n}\n")
            vals = [random.randint(0, 100) for _ in range(n)]
            f.write("\n".join(map(lambda x: str(x), vals)))

        print(sorted(vals))
