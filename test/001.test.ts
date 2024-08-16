import { OrToolsVersion } from "../tssrc/operations_research/OrToolsVersion"

test('001', async () =>
{
    let ver = OrToolsVersion.VersionString()

    expect(ver).toBe('9.0.90411118')

})
