import os

def make_tree_with_comments(root_path, indent=""):
    entries = sorted(os.listdir(root_path))
    dirs = [d for d in entries if os.path.isdir(os.path.join(root_path, d))]
    files = [f for f in entries if os.path.isfile(os.path.join(root_path, f))]

    lines = []

    for d in dirs:
        lines.append(f"{indent}├── {d}/") 
        subpath = os.path.join(root_path, d)
        sublines = make_tree_with_comments(subpath, indent + "│   ")
        lines.extend(sublines)

    for i, f in enumerate(files):
        prefix = "└──" if i == len(files) - 1 else "├──"
        lines.append(f"{indent}{prefix} {f}")

    return lines

def main():
    path = "./nvgpu"
    if not os.path.isdir(path):
        return

    print("nvgpu/")
    tree_lines = make_tree_with_comments(path)
    for line in tree_lines:
        print(line)

if __name__ == "__main__":
    main()
