import argparse
import random

if __name__ == "__main__":
    argparser = argparse.ArgumentParser()
    argparser.add_argument("-n", "--number", help="Number of values", default=50)
    argparser.add_argument("-r", "--range", help="Maximum number", default=100)
    args = argparser.parse_args()

    n = int(args.number)
    m = int(args.range)

    with open("../datos.txt", "w") as f:
        f.write(f"{n}\n")
        vals = [random.randint(0, m) for _ in range(n)]
        f.write("\n".join(map(lambda x: str(x), vals)))

    for i in range(3):
        vals = []
        with open(f"./data/data{i+1}.txt", "w") as f:
            vals = [random.randint(0, m) for _ in range(n // (i + 1))]
            f.write(f"{n // (i + 1)}\n")
            f.write("\n".join(map(lambda x: str(x), vals)))

        with open(f"./validate/test{i+1}.txt", "w") as f:
            f.write(" ".join(map(lambda x: str(x), vals)))
            f.write(" \n")
            vals.sort()
            for i in range(2):
                f.write(" ".join(map(lambda x: str(x), vals)))
                f.write(" \n")
