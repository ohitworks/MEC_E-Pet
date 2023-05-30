# Git仓库规范

仓库样式:

```text
.
├───.git      # git 仓库
├───.idea     # CLion 配置
├───include   # 头文件
├───lib       # 第三方库
├───src       # 代码
└───test      # 测试
```

1. 当你开发完成一部分，代码可以正常编译，且不影响他人代码时，再提交到远程仓库。

4. 别忘了上机测试提交的代码。

举例，A组要开发车辆UI功能

> 假如此时将UI需要的库文件加入了项目，可以提交：
>
> ```bash
> git add -A
> git commit -m "func: add ui lib"
> ```
>
> 接下来A组使用库实现了车辆状态显示功能：
> 
> ```bash
>git add -A
> git commit -m "func: up date car state"
>```
> 
> 在功能添加并提交到后，A组测试并**确定代码能顺利编译**。
> 
> 此时应该将代码提交到远程分支了：
> 
>```bash
> git pull                        # 同步代码
>git push                        # 上传
> ```
> 

最后补充一下：提交信息最好使用英语。

***

（正文）

**目录**

- [分支规范和开发流程](#1)
  - [开发流程](#1.1)
  - [可能情况](#1.2)
  - [本地开发建议](#1.3)
- [标签规范](#2)
  - [版本号](#2.1)
  - [尾缀](#2.2)

- [意外处理](#3)
  - [标签打错了](#标签打错了)
  - [推送/拉取时冲突](#推送/拉取时冲突)
  - [在main/dev上错误提交](#在main/dev上错误提交)

- [推荐git项目配置](#4)

## <span id="1">分支规范和开发流程</span>

远程仓库分支为`main`和`dev`，各位开发者应在本地建立一个`feature`分支作为开发时的“主分支”。

<font color="red">请勿将`feature`等任何本地分支提交到远程仓库</font>，如需同步代码，请新建仓库。

### <span id="1.1">开发流程</span>

常规流程为如下五步：

1. 在本地新建名为`feature`的分支，作为本地开发时的主要分支，开发时请勿操作`dev`分支，更不应该对`main`进行任何操作。

2. 当你开发完成一部分，代码可以正常编译，且不影响他人代码时，可以将`feature`分支合并到`dev`分支上，合并时，需要使用`git merge --no-ff`操作。

   > 请尽量合并通过测试或非常自信的代码，也不要过多或过少合并

3. 合并后，请为刚才的提交打上标签，并提交到远程仓库。

   > 推送提交和推送标签分别是`git push`和`git push --tags`，需要操作两次。

   > 强烈建议提交后**立即**切回feature分支并合并dev代码，避免遗漏

4. 尽快测试提交到`dev`分支的代码。

5. 确认功能开发完成后，告知仓库管理员，他会将在进行代码审查后提交到`main`分支里。

   > `dev`向`main`合并时，应当使用`--no-ff`参数。

开发时若需要从`dev`更新本地开发中的代码，请在更新本地dev后，通过`git merge`更新本地的`feature`分支，注意**不要**使用rebase。

### <span id="1.2">可能情况</span>

- **提交时出现版本不同步**

  向`dev`提交时，可能出现版本不同步，这时运行`git pull`更新本地`dev`代码，正常情况下可以无冲突自动合并，注意此时可能产生一个新提交，注意应该将标签打在新产生的提交上。

  - 若提交时显示冲突，可能是有人在你打标签时提交了，请参考[推送/拉取时冲突](#推送/拉取时冲突)。

- **需要与其他组员进行代码同步**

  **<font color="red">TODO:添加两两传递方法</font>**

  首先选择一个代码托管平台建立一个**私有**仓库。

  执行以下命令，将本地仓库链接到你的远程仓库上：
  
  ```bash
  git remote add {仓库链接名称} {仓库地址}
  ```

  注意仓库链接名称应避开已有名称，在本地运行`git remote -v`可以查看已链接的远程仓库。
  
  提交时使用`git push {仓库链接名称}`指定提交的仓库。
  
- **更新代码需要跳过某个提交**

  本地开发从`dev`更新开发代码时，需要跳过某个提交，那么需要使用`cherry-pick`更新本地`feature`：

  首先同步远程的`dev`：

  ```bash
  git switch develop
  git pull
  ```

  此时可以通过`git log`查看并记录我们要操作的节点。假设此时提交树如下：

  ```mermaid
  sequenceDiagram
  	note over develop : c1 (tag: v1.12.3-alpha)
  	develop ->> feature : pull
  	note over feature : c1 (tag: v1.12.3-alpha)
  	note over develop: c3 (tag: v1.13.0-alpha)
  	feature ->> feature : commit
  	note over feature : c4
  	note over develop: c5 (tag: v1.14.0-alpha)
  	note over develop: c6 (tag: v1.14.1-alpha)
  	develop --> feature : 希望跳过c3更新本地代码
  ```

  我们希望跳过c3，只更新c5、c6两次提交更改的代码：

  ```bash
  git switch feature
  git cherry-pick c3..c6
  ```

  代码中`c3..c6`指：“从c3直到c6的路径，且不包括c3”，即(c3, c6]。

  这时`feature`上增加了两个和c5、c6一样的新提交。

  当前提交树如下：

  ```mermaid
  sequenceDiagram
  	note over develop: c5 (tag: v1.14.0-alpha)
  	note over develop: c6 (tag: v1.14.1-alpha)
  	develop --> feature : 希望跳过c3更新本地代码
  	develop ->> feature : git cherry-pick c3..c6
  	note over feature : c5'
  	note over feature : c6'
  	note right of feature: <- HEAD
  ```

  

### <span id="1.3">本地开发建议</span>

- 本地开发时尽量不使用标签，如果使用了，切勿将自己的标签提交到社团仓库中。
- 合并本地分支时，请尽量使用`rebase`替代`merge`，或为merge操作添加`--ff-only`，这会优化所有人的git使用体验。
- 在进行开发前，使用IDLE的锁定功能（CLion的在右下角）锁定所有不属于你开发范围的文件，避免意外修改其他组的代码。

## <span id="2">标签规范</span>

标签的由“版本号”和”尾缀“两部分组成，样式为`v{版本号}-{尾缀}`。

标签以"v"开头是为方便查找记录时快速从哈希值和标签中筛选出标签。

成员提交的所有标签**应当**带alpha尾缀，只有完成测试和代码审查后才提交无尾缀标签。

此规则大量参考了[语义化版本 2.0.0](https://semver.org/lang/zh-CN/)，推荐阅读。

### <span id="2.1">版本号</span>

版本号格式：`{主版本号}.{次版本号}.{修订号}`。

版本号递增规则如下：

- 主版本号**只能**使用测试通过的代码决定，可能是出现了不兼容的 API 修改；
- 次版本号**只能**在新增功能后，由各小组自行增加，但每个小组可增加的版本号由组会决定；
- 修订号为该提交是之前版本的补丁是增加，由小组自行决定，无限制。

次版本号数量应当由组会根据派发给每个小组的任务决定，且每个版本号应当对应指定的功能，并及时写在文档中。

> 基于 `1.10.3` 开发了表格， 完成时 dev 最新版本是 `1.10.5`
>
> 提交新的版本号是`1.11.0`
>
> 后期有微调，`1.12.3` -> `1.12.4`

### <span id="2.2">尾缀</span>

尾缀代表不确保稳定，所有未经过反复测试和代码审查的代码都应带有尾缀，只有组长彪临轩有权提交无尾缀标签。

基础的尾缀是`alpha`，其余尾缀待定。

## <span id="3">意外处理</span>

- **<span id="标签打错了">标签打错了</span>**

  执行`git tag -d {标签}`删除本地标签，

  若错误标签已上传仓库，执行

  ````bash
  git push origin --delite tags {标签}  # origin可替换成要修改的远程仓库代号
  ````

  删除远程标签。

  删除后重新打标签即可。

- **<span id="推送/拉取时冲突">推送/拉取时冲突</span>**

  当api设计合理、开发流程规范时，推送、拉取代码并不会发生冲突。当然，实际操作时总会因为种种原因出现冲突。

  首先根据错误信息判断冲突原因：

  - 提交代码时，提示中有`hint: (e.g., 'git pull ...') before pushing again.`字样，可尝试先从远程库中拉取代码，解决冲突后再尝试提交。
  - 拉取代码时，提示中有`hint: your next pull:`字样，请添加`--rebase`关键字（或相关设置）后重新拉取。

  > 当使用rebase合并代码出现冲突时：
  >
  > - 使用`git stash`查看冲突的文件；
  >
  > - 修改完某冲突文件后，运行`git add {文件名}`标记为已解决该文件的冲突；
  >
  > - 冲突全部解决后，运行`git rebase --continue`提交冲突，若运行后进入编辑界面，编辑的文本将成为刚才解决冲突的提交的新提交信息。
  
- **<span id="在main/dev上错误提交">在main/dev上错误提交</span>**

  ```mermaid
  sequenceDiagram
  	note over remote/dev : c1 (tag: v1.12.3-alpha)
  	remote/dev ->> local/dev : pull
  	note over local/dev : c1 (tag: v1.12.3-alpha)
  	remote/dev ->> remote/dev : commit
  	note over remote/dev: c3 (tag: v1.13.0-alpha)
  	local/dev ->> local/dev : commit
  	note over local/dev : c4
  	note over remote/dev, local/dev : 发现问题
  ```

  

  若你还没有把代码推上去，别着急，这个问题很容易解决：

  首先，确定你还没有打标签，如果打了，请删除。

  第二步，检查本地dev分支最近的标签：

  ```bash
  git describe --tags
  ```

  记住输出的标签。

  移动提交的分支：

  ```bash
  git rebase --onto feature {标签} develop
  ```

  > 此时很可能出现冲突，这是你几次提交冲突了。
  >
  > 这时先放弃rebase，在`feature`分支执行`git reset --hard {标签} `后，再次rebase即可

  这个名称顺便会让你切到`dev`分支，接下来需要切回并更新本地`feature`分支：

  ```bash
  git switch feature
  git reset --hard develop
  ```

  最后，回调`dev`至标签即可：

  ```bash
  git switch develop
  git reset --hard {标签}
  ```

  至此，问题解决，切到`feature`继续开发即可。

  插一句，如果你已经把错误提交推上去了——就这样吧。

## <span id="4">推荐git项目配置</span>

```bash
git conifg pull.rebase   true
git config core.autocrlf false
git config core.safecrlf true
git config merge.ff      only
```

***

（修订记录）

| 版本号 | 日期      | 发布者      | 信息                             |
| ------ | --------- | ----------- | -------------------------------- |
| V1.0   | 2022-8-17 | 住建部(DOG) | 初始版本                         |
| V1.1   | 2022-8-17 | 住建部(DOG) | 修复了html部分目录无法跳转的问题 |
| V1.2   | 2023-4-28 | oh it works | 删去了隐私信息                   |
| V2.0   | 2023-5-4  | oh it works | 简化了仓库要求                   |
