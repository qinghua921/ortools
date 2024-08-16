import { OrToolsVersion } from "../tssrc/operations_research/OrToolsVersion"
import { MPSolver } from "../tssrc/operations_research/MPSolver"

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

test('005', () =>
{
    let solver = MPSolver.CreateSolver("BOP_INTEGER_PROGRAMMING")
    expect(solver).not.toBeUndefined()
})