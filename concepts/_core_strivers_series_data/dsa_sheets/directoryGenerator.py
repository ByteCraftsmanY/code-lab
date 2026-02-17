import os
import json
import re

data: dict = {}

with open("concepts/_core_strivers_series_data/dsa_sheets/striver-sde-sheet.json") as f:
    data = json.loads(f.read())

sheetData = data.get("sheetData")


def createDir(path: str):
    try:
        os.mkdir(path=path)
    except FileExistsError as e:
        # print(f"alrady exists: {e}")
        pass
    except Exception as e:
        print(f"Got Exception: {e}")


parent_dir = "DSA/Strivers_SDE_Sheet"
createDir(parent_dir)


def get_difficulty(i: int) -> str:
    if i == 0:
        return "Easy"
    elif i == 1:
        return "Medium"
    elif i == 2:
        return "Hard"
    return ""


def sanitize_filename(filename):
    # Separate the base name and extension
    name, extension = os.path.splitext(filename)

    # Define allowed characters: letters, numbers, spaces, dots, underscores, hyphens
    # The pattern [^a-zA-Z0-9 ._-] matches any character *not* in the set
    # and replaces it with an empty string.
    sanitized_name = re.sub(r'[^a-zA-Z0-9 ._-]', '', name)

    # Combine the sanitized name and original extension
    cleaned_filename = sanitized_name + extension
    return cleaned_filename


for step in sheetData:
    head_step: str = step['head_step_no']
    head_step = head_step.replace(' ', '_')
    sub_dir: str = f"Step_{step['step_no']}_{head_step}"
    createDir(f"{parent_dir}/{sub_dir}")
    # continue
    topics = step["topics"]
    for i, topic in enumerate(topics):
        try:
            problem: str = topic['title']
            problem = problem.replace(' ', '_')
            problem = sanitize_filename(problem)
            filename: str = f"Problem_{i+1}_{problem}.cpp"
            with open(f"{parent_dir}/{sub_dir}/{filename}", "w", encoding='utf-8') as file:
                data = f"""// {topic['title']}
// Step: {topic['head_step_no']}
// Difficulty: {get_difficulty(topic['difficulty'])}
// Post Link: {topic['post_link']}
// LeetCode Link: {topic['lc_link']}
// GFG Link: {topic['gfg_link']}

#include <bits/stdc++.h>
using namespace std;

int main() {{
    return 0;
}}
                """
                file.write(data)
        except Exception as e:
            print("got exception: ", e)
