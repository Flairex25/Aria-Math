The all in one Clickteam Fusion 2.5 Math Extension

This repository contains the source code for 'Aria Math' along with the free version build of the extension.
You can build the full version for free using this repository.

If you instead want to purchase the extension, you can find it on my Ko-Fi page here: https://ko-fi.com/s/7ad22d8ff4?preview=true 



## Build Instructions

1.) Download the source code zip file from this repository

2.) Download the `MMF2Exts-master` repository from here: https://github.com/SortaCore/MMF2Exts

3.) Unzip the source code and move the folder into your `MMF2Exts-master directory`, specifically to `"MMF2Exts-master\DarkEdif"`

4.) Rename the folder to `"Aria Math"`

5.) Open the `AriaMath.sln"` file and build the solution from Visual Studio.

(Note: You must have Visual Studio along with the proper development kits installed for the solution to be able to build.)
(Make sure you build the `Edittime`, `Edittime Unicode`, `Runtime` and `Runtime Unicode` builds. Once built, you can find them inside `"Aria Math\MFX"`.)

## If your build doesn't work

- Make sure you have everything you need for Visual Studio. This includes the latest version of the Windows SDK.
- Make sure your directory inside the extension manager is correct and that the folder is named `"Aria Math"`.
- If you are still getting errors, try replacing the `Inc` and `Lib` folders with the ones found in `Extra-Repo-Items`.
