CREATE PROCEDURE [dbo].[GetAccount]
	@accountId INT
AS
BEGIN
	SET NOCOUNT ON
	SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED

	SELECT
	-- BEGIN_ROW : accountInfo
	Id				-- int
	, Name			-- nvarchar(256)
	, LoginAt		-- DateTime
	-- END_ROW
	FROM Account
	where @accountId = Id

	RETURN 0
END
