# Nefta Unreal Toolbox SDK

Toolbox for ease of web3 integration.

Copy this (NeftaToolboxSDK) folder and it's content in your unreal Project /Plugins.

Set your Nefta marketplace id in Unreal editor Project settings (Menu: Edit > Project Settings..).

## Sample integrations

In NeftaToolboxSDK Content there are two sample integrations:

### Demo-Script
Integration in C++ with minimal overhead. Make sure to call:

`FNeftaToolboxSDKModule::Get().Init();`

Before accessing any other module method.

### Demo-BP
Integration with Blueprints.