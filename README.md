# 模组开发模板 (Endfield-ModTemplate)

适用于 ZML 的《明日方舟：终末地》模组开发仓库模板。

## 功能特性

- **标准模组脚手架**：采用 C++20 与公开 `zml_plugin.h` 接口标准，预置完整的模组清单（`mod.ini`）、配置结构与产物打包规范。
- **开箱即用的构建流程**：包含本地自动化构建与打包脚本（`tools/build.ps1`、`tools/package.ps1`）。
- **自动化发版与索引 PR**：配置 GitHub Actions 工作流（`.github/workflows/release.yml`），打 Tag 发版时自动构建产物并向官方模组索引库 (`Endfield-ModIndex`) 提交收录 PR。
