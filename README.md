# MASR Audio Plugin Template

### On the Web

- Create a Github Account with your university email
- Go to this repo - https://github.com/BlushAudioLab/MASRAudioPluginTemplate.git and click 'Use this template' and 'Create a new repository' - DO NOT SELECT 'Open in a codespace'
- Name it and add a description
- In your new repo go to 'Code', 'Local', 'HTTPS' and copy the URL

### On your Mac

- Launch 'Terminal'
- Enter the command 'cd Desktop'
- Enter the command 'mkdir Digital\ Audio\ Programming'
- Enter the command 'cd Digital\ Audio\ Programming'
- In Terminal type 'git clone \<your directory>
- Open CLion - Open Project - Desktop/Digital Audio Programming/ \<your project folder>
- In the 'Open Project Wizard' just use the default configurations for compilers etc...
- On the next page tick 'Reload CMake Project on editing...' and keep everything else as is. Hit 'Finish'.
- Open the CMakeLists.txt file from within CLion andModify the following variables with your own values:
    - COMPANY_NAME
    - PLUGIN_MANUFACTURER_CODE
    - PLUGIN_CODE
    - PRODUCT_NAME
- You can now use the built-in Terminal in CLion instead of the standalone Mac version
- Go to the 'CMake' tab and hit the refresh button check it builds properly - will create a new folder called 'cmake-build-debug' - this is where your files live
- Now go up to the top and hit 'build'
- If that succeeds hit 'run'
- The standalone version of the plugin should open up and display the text "Hello York!"
- You're ready to start coding!

### Requirements

Mac OS Sequoia+
<br>XCode V26+