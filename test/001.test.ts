import { OrToolsVersion } from "../tssrc/operations_research/OrToolsVersion"

test('001', () =>
{
    let VersionString = OrToolsVersion.VersionString()
    expect(VersionString).toBe('9.6.2534')
})

test('002', () =>
{
    let MajorNumber = OrToolsVersion.MajorNumber()
    expect(MajorNumber).toBe(9)
})

test('003', () =>
{
    let MinorNumber = OrToolsVersion.MinorNumber()
    expect(MinorNumber).toBe(6)
})

test('004', () =>
{
    let PatchNumber = OrToolsVersion.PatchNumber()
    expect(PatchNumber).toBe(2534)
})