import json
import os
import subprocess
import sys
import time
from itertools import zip_longest

TIMEOUT = 10
COMPILED_FILE_PATH = "o"
DEFAULT_TEST_DATA_SUFFIX = "_test_data.json"


def compile_clang(file_path):
    print("Compiling C/C++ file...")
    command = ["clang++", "-I/usr/local/include/c++/v1", "-L/usr/local/lib", "-I/opt/boost/clang/include",
               "-L/opt/boost/clang/lib", "-std=c++14", "-stdlib=libc++", "-O2", "-o", COMPILED_FILE_PATH, file_path]
    res = subprocess.run(command)
    if res.returncode != 0:
        sys.stderr.write("Failed to compile C/C++ code.\n")
        exit(1)
    print("Finished compiling.")
    return COMPILED_FILE_PATH


def convert_str_to_val_of_list_list(list_list):
    return [[float(item) for item in line.split(" ")]for line in list_list]


def remove_tail_empty_item(item_list):
    if item_list and not item_list[len(item_list) - 1]:
        del item_list[len(item_list) - 1]
    return item_list


def main():
    if len(sys.argv) == 2:
        source_path = sys.argv[1]
        source_bodyname, source_ext = os.path.splitext(source_path)
        # C, C++のソースファイルならコンパイルする
        if source_ext in [".c", ".cpp"]:
            executable_path = compile_clang(source_path)
            test_data_path = os.path.join(
                source_bodyname + DEFAULT_TEST_DATA_SUFFIX)
        else:
            sys.stderr.write("Unknown language({}).\n".format(source_ext))
            exit(1)
    elif len(sys.argv) == 3:
        executable_path = sys.argv[1]
        test_data_path = sys.argv[2]
    else:
        sys.stderr.write(
            "2 parameters (executable_path and test_data_path) or 1 parameter (cource_file_path) are required.\n")
        exit(1)
    with open(test_data_path, "r") as test_data_file:
        test_data_obj = json.load(test_data_file)
    test_data_list = test_data_obj["test_data"]
    try:
        output_matching = test_data_obj["test_setting"]["output_matching"]
    except KeyError:
        output_matching = "string"
    success_count = 0
    failed_count = 0
    for idx, test_data in enumerate(test_data_list):
        print("=====In test {}=====".format(idx))
        input_data = test_data["input"]
        output_data = test_data["output"]
        proc = subprocess.Popen("./{}".format(
            executable_path), stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
        start_time = time.perf_counter()
        outputed_lines = [stdout_line.rstrip("\n") for stdout_line in proc.communicate(
            ("\n".join(input_data) + "\n").encode('utf-8'), timeout=TIMEOUT)[0].decode('utf-8').split("\n")]
        # 末尾の空データを除去する
        output_data = remove_tail_empty_item(output_data)
        outputed_lines = remove_tail_empty_item(outputed_lines)
        # 出力を値として扱う
        if output_matching == "value":
            output_data = convert_str_to_val_of_list_list(output_data)
            outputed_lines = convert_str_to_val_of_list_list(outputed_lines)
        elapsed_time = time.perf_counter() - start_time
        if all([output_data_line == outputed_line for output_data_line, outputed_line in zip_longest(output_data, outputed_lines)]):
            print("Test suceed! (elapsed time: {:,.3f}ms)".format(
                elapsed_time * 1000))
            success_count += 1
        else:
            print("Test failed... (elapsed time: {:,.3f}ms)".format(
                elapsed_time * 1000))
            print("---Input---")
            print("\n".join(input_data))
            print("---Expected output---")
            print("\n".join(output_data))
            print("---Actual output---")
            print("\n".join(outputed_lines))
            failed_count += 1
    print("=====Total result=====")
    if failed_count == 0:
        print("All {} tests are succeed!".format(success_count))
    elif success_count == 0:
        print("All {} tests are failed...".format(failed_count))
    else:
        print("{} tests are succeed and {} tests are failed.".format(
            success_count, failed_count))


if __name__ == "__main__":
    main()
