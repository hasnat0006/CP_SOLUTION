import os

def create_folders():
    try:
        # Create 20 folders
        for i in range(1001, 1025):
            folder_name = f"Round {i} (Div. 2)"
            os.makedirs(folder_name)
            print(f"Folder created: {folder_name}")
    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function to create folders
create_folders()
