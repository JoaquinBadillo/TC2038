if __name__ == "__main__":
    for i in range(1, 4):
        with open(f"./results/test{i}.txt", "r") as f:
            with open(f"./validate/test{i}.txt", "r") as g:
                count = 0
                for _ in range(3):
                    if (f.readline() == g.readline()):
                        count += 1
                if count == 3:
                    print(f"SUCCESS: ({count}/3)")
                else:
                    print(f"FAILED: ({count}/3)")
