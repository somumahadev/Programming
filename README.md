# Programming

# Install Python 3.9 and Set Up Virtual Environment on Ubuntu

## Step 1: Update and Upgrade System
```bash
sudo apt update && sudo apt upgrade -y
```

## Step 2: Install Required Dependencies
```bash
sudo apt install software-properties-common -y
```

## Step 3: Add Deadsnakes PPA (For Latest Python Versions)
```bash
sudo add-apt-repository ppa:deadsnakes/ppa -y
sudo apt update
```

## Step 4: Install Python 3.9
```bash
sudo apt install python3.9 python3.9-venv python3.9-dev -y
```

## Step 5: Verify Python Installation
```bash
python3.9 --version
```

## Step 6: Create a Virtual Environment
### Navigate to Your Project Directory
```bash
mkdir myproject && cd myproject
```

### Create Virtual Environment
```bash
python3.9 -m venv venv
```

## Step 7: Activate Virtual Environment
### For Bash, Zsh:
```bash
source venv/bin/activate
```

### For Fish Shell:
```bash
source venv/bin/activate.fish
```

### For Windows (if using WSL):
```bash
source venv/bin/activate
```

## Step 8: Verify Virtual Environment
```bash
python --version  # Should show Python 3.9.x
```

## Step 9: Install Required Python Packages
Example:
```bash
pip install --upgrade pip
pip install numpy pandas flask
```

## Step 10: Deactivate Virtual Environment
To exit the virtual environment:
```bash
deactivate
```

## Notes
- Always activate the virtual environment before installing packages.
- Use `deactivate` to exit the virtual environment when done.

### Enjoy your Python 3.9 environment on Ubuntu! 🚀
