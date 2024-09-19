export namespace operations_research
{
    export namespace MPSolverParameters
    {
        enum DoubleParam
        {
            RELATIVE_MIP_GAP = 0,
            PRIMAL_TOLERANCE = 1,
            DUAL_TOLERANCE = 2
        };

        enum IntegerParam
        {
            PRESOLVE = 1000,
            LP_ALGORITHM = 1001,
            INCREMENTALITY = 1002,
            SCALING = 1003
        };

        enum PresolveValues
        {
            PRESOLVE_OFF = 0,
            PRESOLVE_ON = 1
        };

        enum LpAlgorithmValues
        {
            DUAL = 10,
            PRIMAL = 11,
            BARRIER = 12
        };

        enum IncrementalityValues
        {
            INCREMENTALITY_OFF = 0,
            INCREMENTALITY_ON = 1
        };

        enum ScalingValues
        {
            SCALING_OFF = 0,
            SCALING_ON = 1
        };
    }

    export class MPSolverParameters
    {
        // public:
        //     static const double               kDefaultDoubleParamValue;
        //     static const int                  kDefaultIntegerParamValue;
        //     static const double               kUnknownDoubleParamValue;
        //     static const int                  kUnknownIntegerParamValue;
        //     static const double               kDefaultRelativeMipGap;
        //     static const double               kDefaultPrimalTolerance;
        //     static const double               kDefaultDualTolerance;
        //     static const PresolveValues       kDefaultPresolve;
        //     static const IncrementalityValues kDefaultIncrementality;
        //     MPSolverParameters();
        // #ifndef SWIG
        //     MPSolverParameters( const MPSolverParameters& )            = delete;
        //     MPSolverParameters& operator=( const MPSolverParameters& ) = delete;
        // #endif
        //     void   SetDoubleParam( MPSolverParameters::DoubleParam param, double value );
        //     void   SetIntegerParam( MPSolverParameters::IntegerParam param, int value );
        //     void   ResetDoubleParam( MPSolverParameters::DoubleParam param );
        //     void   ResetIntegerParam( MPSolverParameters::IntegerParam param );
        //     void   Reset();
        //     double GetDoubleParam( MPSolverParameters::DoubleParam param ) const;
        //     int    GetIntegerParam( MPSolverParameters::IntegerParam param ) const;

    };

}