import os
import shutil

def delete_files_and_directories(directory):
    try:
        # Iterate over all entries in the directory
        for entry in os.listdir(directory):
            entry_path = os.path.join(directory, entry)
            # Check if the entry is a directory
            if os.path.isdir(entry_path):
                # Check if the directory name matches any of the specified names
                if entry in [".cph", ".vscode", "output"]:
                    # Remove the directory
                    shutil.rmtree(entry_path)
                    print(f"Deleted directory: {entry_path}")
                else:
                    # Recursively call the function for subdirectories
                    delete_files_and_directories(entry_path)
            # Check if the entry is a file
            elif os.path.isfile(entry_path):
                # Check if the file extension matches any of the specified extensions
                if entry.endswith((".exe", ".bin")):
                    # Remove the file
                    os.remove(entry_path)
                    print(f"Deleted file: {entry_path}")
    except Exception as e:
        print(f"An error occurred: {e}")

# Specify the directory containing the files and directories to be deleted
directory_path = "C:\\Users\\Yusuf Reza Hasnat\\OneDrive\\Desktop\\CP\\CP"

# Call the function to delete the files and directories
delete_files_and_directories(directory_path)
