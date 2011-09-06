/* +------------------------------------------------------------------------+
   | quix86                                                                 |
   +------------------------------------------------------------------------+
   | This file is part of quix86, an x86-64 instruction decoder.            |
   |                                                                        |
   | Copyright (C) 2011 Institute for System Programming of Russian Academy |
   | of Sciences.                                                           |
   |                                                                        |
   | Contact e-mail: <unicluster@ispras.ru>.                                |
   |                                                                        |
   | quix86 is free software: you can redistribute it and/or modify it      |
   | under the terms of the GNU General Public License as published by the  |
   | Free Software Foundation, either version 3 of the License, or (at your |
   | option) any later version.                                             |
   |                                                                        |
   | quix86 is distributed in the hope that it will be useful, but WITHOUT  |
   | ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or  |
   | FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License  |
   | for more details.                                                      |
   |                                                                        |
   | You should have received a copy of the GNU General Public License      |
   | along with quix86.  If not, see <http://www.gnu.org/licenses/>.        |
   +------------------------------------------------------------------------+ */

/* Reference: see BOUND.  */
static qx86_stuple                      qx86_stuple_a
                                        =
{
    "a",                                "a",

    {
        "BARR4",                        "BARR8",
        0,                              0
    },

    {
        4,                              8,
        0,                              0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_b
                                        =
{
    "b",                                "b",

    {
        "BYTE",                         "BYTE",
        "BYTE",                         0
    },

    {
        1,                              1,
        1,                              0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_d
                                        =
{
    "d",                                "d",

    {
        "DWORD",                        "DWORD",
        "DWORD",                        0
    },

    {
        4,                              4,
        4,                              0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_dq
                                        =
{
    "dq",                               "dq",

    {
        "OWORD",                        "OWORD",
        "OWORD",                        0
    },

    {
        16,                             16,
        16,                             0
    }
};

/* Reference: see FNSAVE.  */
static qx86_stuple                      qx86_stuple_f
                                        =
{
    "f",                                "f",

    {
        "F94",                          "F108",
        "F108",                         0
    },

    {
        94,                             108,
        108,                            0
    }
};

/* Reference: see FSTENV.  */
static qx86_stuple                      qx86_stuple_fe
                                        =
{
    "fe",                               "fe",

    {
        "FE14",                         "FE28",
        "FE28",                         0
    },

    {
        14,                             28,
        28,                             0
    }
};

/* Reference: see FXSAVE.  */
static qx86_stuple                      qx86_stuple_fx
                                        =
{
    "fx",                               "fx",

    {
        "FX512",                        "FX512",
        "FX512",                        0
    },

    {
        512,                            512,
        512,                            0
    }
};

/* Reference: see LEA.  */
static qx86_stuple                      qx86_stuple_i
                                        =
{
    "",                                 "",

    {
        "",                             "",
        "",                             0
    },

    {
        0,                              0,
        0,                              0
    }
};

/* Reference: see JMPF.  */
static qx86_stuple                      qx86_stuple_p
                                        =
{
    "p",                                "p",

    {
        "FAR4",                         "FAR6",
        0,                              0
    },

    {
        4,                              6,
        0,                              0
    }
};

/* Reference: see MOVUPD.  */
static qx86_stuple                      qx86_stuple_pd
                                        =
{
    "pd",                               "pd",

    {
        "OWORD",                        "OWORD",
        "OWORD",                        0
    },

    {
        16,                             16,
        16,                             0
    }
};

/* Reference: see MOVLPD.  */
static qx86_stuple                      qx86_stuple_ps
                                        =
{
    "ps",                               "ps",

    {
        "OWORD",                        "OWORD",
        "OWORD",                        0
    },

    {
        16,                             16,
        16,                             0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_q
                                        =
{
    "q",                                "q",

    {
        "QWORD",                        "QWORD",
        "QWORD",                        0
    },

    {
        8,                              8,
        8,                              0
    }
};

/* Reference: see LGDT.  */
static qx86_stuple                      qx86_stuple_s
                                        =
{
    "s",                                "s",

    {
        "PD6",                          "PD6",
        "PD10",                         0
    },

    {
        6,                              6,
        10,                             0
    }
};

/* Reference: see FBLD.  */
static qx86_stuple                      qx86_stuple_sb
                                        =
{
    "sb",                               "sb",

    {
        "TWORD",                        "TWORD",
        "TWORD",                        0
    },

    {
        10,                             10,
        10,                             0
    }
};

/* Reference: see MOVSD.  */
static qx86_stuple                      qx86_stuple_sd
                                        =
{
    "sd",                               "sd",

    {
        "QWORD",                        "QWORD",
        "QWORD",                        0
    },

    {
        8,                              8,
        8,                              0
    }
};

/* Reference: see FLD.  */
static qx86_stuple                      qx86_stuple_se
                                        =
{
    "se",                               "se",

    {
        "TWORD",                        "TWORD",
        "TWORD",                        0
    },

    {
        10,                             10,
        10,                             0
    }
};

/* Reference: see MOVSS.  */
static qx86_stuple                      qx86_stuple_ss
                                        =
{
    "ss",                               "ss",

    {
        "DWORD",                        "DWORD",
        "DWORD",                        0
    },

    {
        4,                              4,
        4,                              0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_v
                                        =
{
    "v",                                "v",

    {
        "WORD",                         "DWORD",
        "QWORD",                        0
    },

    {
        2,                              4,
        8,                              0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_w
                                        =
{
    "w",                                "w",

    {
        "WORD",                         "WORD",
        "WORD",                         0
    },

    {
        2,                              2,
        2,                              0
    }
};

/* Reference: none.  */
static qx86_stuple                      qx86_stuple_z
                                        =
{
    "z",                                "z",

    {
        "WORD",                         "DWORD",
        "DWORD",                        0
    },

    {
        2,                              4,
        4,                              0
    }
};
