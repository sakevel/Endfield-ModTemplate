# Endfield-ModTemplate

适用于 ZML (ZMDModLoader / ZeroModLoader / ZMLModLoader) 的《明日方舟：终末地》模组项目模板。

## 特性

- 采用 C++20 与公开 `zml_plugin.h` ABI1 标准。
- 预置完整的独立热重载及配置结构（`mod.ini`、`config.ini`、`zml-package.json`）。
- 包含自动化构建与打包脚本（`build.ps1`、`package.ps1`）。
- 包含 GitHub Actions 自动化发版流（`.github/workflows/release.yml`）：
  - 标签触发自动打包构件并上传 Release。
  - 自动向模组索引中心 (`Endfield-ModIndex`) 提交更新 Pull Request。

## 本地构建

```powershell
.\tools\build.ps1
.\tools\package.ps1
```
