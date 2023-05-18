/*
Auth의 배포 스크립트

이 코드는 도구를 사용하여 생성되었습니다.
파일 내용을 변경하면 잘못된 동작이 발생할 수 있으며, 코드를 다시 생성하면
변경 내용이 손실됩니다.
*/

GO
SET ANSI_NULLS, ANSI_PADDING, ANSI_WARNINGS, ARITHABORT, CONCAT_NULL_YIELDS_NULL, QUOTED_IDENTIFIER ON;

SET NUMERIC_ROUNDABORT OFF;


GO
:setvar DatabaseName "Auth"
:setvar DefaultFilePrefix "Auth"
:setvar DefaultDataPath "D:\PC\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\"
:setvar DefaultLogPath "D:\PC\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\DATA\"

GO
:on error exit
GO
/*
SQLCMD 모드가 지원되지 않으면 SQLCMD 모드를 검색하고 스크립트를 실행하지 않습니다.
SQLCMD 모드를 설정한 후에 이 스크립트를 다시 사용하려면 다음을 실행합니다.
SET NOEXEC OFF; 
*/
:setvar __IsSqlCmdEnabled "True"
GO
IF N'$(__IsSqlCmdEnabled)' NOT LIKE N'True'
    BEGIN
        PRINT N'이 스크립트를 실행하려면 SQLCMD 모드를 사용하도록 설정해야 합니다.';
        SET NOEXEC ON;
    END


GO
USE [$(DatabaseName)];


GO
IF EXISTS (SELECT 1
           FROM   [master].[dbo].[sysdatabases]
           WHERE  [name] = N'$(DatabaseName)')
    BEGIN
        ALTER DATABASE [$(DatabaseName)]
            SET ANSI_NULLS ON,
                ANSI_PADDING ON,
                ANSI_WARNINGS ON,
                ARITHABORT ON,
                CONCAT_NULL_YIELDS_NULL ON,
                QUOTED_IDENTIFIER ON,
                ANSI_NULL_DEFAULT ON,
                CURSOR_DEFAULT LOCAL 
            WITH ROLLBACK IMMEDIATE;
    END


GO
IF EXISTS (SELECT 1
           FROM   [master].[dbo].[sysdatabases]
           WHERE  [name] = N'$(DatabaseName)')
    BEGIN
        ALTER DATABASE [$(DatabaseName)]
            SET PAGE_VERIFY NONE 
            WITH ROLLBACK IMMEDIATE;
    END


GO
ALTER DATABASE [$(DatabaseName)]
    SET TARGET_RECOVERY_TIME = 0 SECONDS 
    WITH ROLLBACK IMMEDIATE;


GO
IF EXISTS (SELECT 1
           FROM   [master].[dbo].[sysdatabases]
           WHERE  [name] = N'$(DatabaseName)')
    BEGIN
        ALTER DATABASE [$(DatabaseName)]
            SET QUERY_STORE (QUERY_CAPTURE_MODE = ALL, CLEANUP_POLICY = (STALE_QUERY_THRESHOLD_DAYS = 367), MAX_STORAGE_SIZE_MB = 100) 
            WITH ROLLBACK IMMEDIATE;
    END


GO
IF EXISTS (SELECT 1
           FROM   [master].[dbo].[sysdatabases]
           WHERE  [name] = N'$(DatabaseName)')
    BEGIN
        ALTER DATABASE [$(DatabaseName)]
            SET QUERY_STORE = OFF 
            WITH ROLLBACK IMMEDIATE;
    END


GO
PRINT N'키가 397de9ba-1c15-4a9a-8082-1345a4fa0ee8, fae92190-b516-46f4-82c2-e6c6cf341165인 이름 바꾸기 리팩터링 작업을 건너뜁니다. 요소 [dbo].[Account].[Age](SqlSimpleColumn)의 이름이 LoginAt(으)로 바뀌지 않습니다.';


GO
PRINT N'테이블 [dbo].[Account]을(를) 만드는 중...';


GO
CREATE TABLE [dbo].[Account] (
    [Id]      INT           NOT NULL,
    [Name]    VARCHAR (255) NOT NULL,
    [LoginAt] DATETIME      NOT NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC)
);


GO
PRINT N'프로시저 [dbo].[GetAccount]을(를) 만드는 중...';


GO
CREATE PROCEDURE [dbo].[GetAccount]
	@accountId INT
AS
BEGIN
	SET NOCOUNT ON
	SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED

	SELECT
	-- BEGIN_ROW : accountInfo
	Id				-- int
	, Name			-- char(256)
	, LoginAt		-- DateTime
	-- END_ROW
	FROM Account

	RETURN 0
END
GO
-- 배포된 트랜잭션 로그를 사용하여 대상 서버를 업데이트하는 리팩터링 단계

IF OBJECT_ID(N'dbo.__RefactorLog') IS NULL
BEGIN
    CREATE TABLE [dbo].[__RefactorLog] (OperationKey UNIQUEIDENTIFIER NOT NULL PRIMARY KEY)
    EXEC sp_addextendedproperty N'microsoft_database_tools_support', N'refactoring log', N'schema', N'dbo', N'table', N'__RefactorLog'
END
GO
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = '397de9ba-1c15-4a9a-8082-1345a4fa0ee8')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('397de9ba-1c15-4a9a-8082-1345a4fa0ee8')
IF NOT EXISTS (SELECT OperationKey FROM [dbo].[__RefactorLog] WHERE OperationKey = 'fae92190-b516-46f4-82c2-e6c6cf341165')
INSERT INTO [dbo].[__RefactorLog] (OperationKey) values ('fae92190-b516-46f4-82c2-e6c6cf341165')

GO

GO
PRINT N'업데이트가 완료되었습니다.';


GO
