import os
import subprocess
from datetime import datetime

def get_current_date():
    # Get current date and format it as '26 MARCH 2024'
    return datetime.now().strftime('%d %B %Y')

def git_commit_push(repo_path, commit_message):
    try:
        # Change working directory to the repository path
        os.chdir(repo_path)
        
        # Add all files to staging area
        subprocess.run(['git', 'add', '.'])
        
        # Commit changes with the current date as the commit message
        subprocess.run(['git', 'commit', '-m', commit_message])
        
        # Push changes to remote repository
        subprocess.run(['git', 'push', 'origin', 'main'])  # Assuming 'main' branch
        
        print("Files committed and pushed successfully.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Specify the path to your local repository
repository_path = "C:\\Users\\Yusuf\\OneDrive\\Desktop\\CP\\CP_SOLUTION"

# Generate the commit message with the current date
commit_message ="DATE: " +  get_current_date()

# Call the function to commit and push changes
git_commit_push(repository_path, commit_message)
