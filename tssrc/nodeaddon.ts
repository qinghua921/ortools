export const ortools = require('../build/Release/ortools_binding.node')

import { BoolVar } from "./operations_research/sat/BoolVar"
import { IntVar } from "./operations_research/sat/IntVar"
import { LinearExpr } from "./operations_research/sat/LinearExpr"

export type CanAsLinearExpr = LinearExpr | BoolVar | IntVar | number




