    const fvMesh& mesh = fluidRegions[i];

    combustionModels::rhoCombustionModel& reaction = reactionFluid[i];
    rhoReactionThermo& thermo = reaction.thermo();
    basicMultiComponentMixture& composition = reactionFluid[i].thermo().composition();	
    PtrList<volScalarField>& Y = composition.Y(); 
    thermo.validate(args.executable(), "h", "e");

    volScalarField& rho = rhoFluid[i];
    volVectorField& U = UFluid[i];
    surfaceScalarField& phi = phiFluid[i];
    volScalarField& dQ = dQFluid[i];


    compressible::turbulenceModel& turb = turbulence[i];

    volScalarField& p = thermo.p();
    const volScalarField& psi = thermo.psi();

    IOMRFZoneList& MRF = MRFfluid[i];
    fv::options& fvOptions = fluidFvOptions[i];

    const dimensionedScalar initialMass
    (
        "initialMass",
        dimMass,
        initialMassFluid[i]
    );

    radiation::radiationModel& rad = radiation[i];

    const label pRefCell = pRefCellFluid[i];
    const scalar pRefValue = pRefValueFluid[i];
    const bool frozenFlow = frozenFlowFluid[i];

    volScalarField& p_rgh = p_rghFluid[i];

    const dimensionedVector& g = gFluid[i];
    const volScalarField& gh = ghFluid[i];
    const surfaceScalarField& ghf = ghfFluid[i];
    
    multivariateSurfaceInterpolationScheme<scalar>::fieldTable fields = fieldsFluid[i];
    
    const word inertSpecie(thermo.lookup("inertSpecie"));

