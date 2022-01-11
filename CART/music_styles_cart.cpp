#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[383] <= 5.810395) {
		if (features[258] <= 274.379) {
			if (features[323] <= 26.77445) {
				if (features[261] <= 31.0895) {
					return ( "jazz");
				} else {
					if (features[2] <= 250.031) {
						return ( "classical");
					} else {
						if (features[1] <= 134.996) {
							return ( "classical");
						} else {
							return ( "jazz");
						}
					}
				}
			} else {
				if (features[0] <= 52.9471) {
					return ( "jazz");
				} else {
					return ( "classical");
				}
			}
		} else {
			if (features[3] <= 447.2735) {
				return ( "jazz");
			} else {
				return ( "country");
			}
		}
	} else {
		if (features[503] <= 60.528999999999996) {
			if (features[70] <= 105.0935) {
				if (features[258] <= 966.3195) {
					if (features[466] <= 2.82424) {
						if (features[294] <= 187.5655) {
							if (features[117] <= 6.976100000000001) {
								if (features[15] <= 72.86905) {
									return ( "jazz");
								} else {
									if (features[116] <= 6.919225000000001) {
										if (features[15] <= 126.65350000000001) {
											if (features[0] <= 46.262600000000006) {
												return ( "disco");
											} else {
												return ( "blues");
											}
										} else {
											return ( "classical");
										}
									} else {
										return ( "country");
									}
								}
							} else {
								if (features[3] <= 871.9659999999999) {
									return ( "jazz");
								} else {
									return ( "rock");
								}
							}
						} else {
							if (features[21] <= 169.67649999999998) {
								return ( "blues");
							} else {
								return ( "jazz");
							}
						}
					} else {
						if (features[487] <= 1.2890350000000002) {
							if (features[6] <= 403.322) {
								if (features[260] <= 423.7585) {
									if (features[99] <= 19.2831) {
										if (features[5] <= 239.11599999999999) {
											return ( "jazz");
										} else {
											if (features[3] <= 570.5045) {
												if (features[4] <= 328.842) {
													return ( "hiphop");
												} else {
													return ( "country");
												}
											} else {
												return ( "blues");
											}
										}
									} else {
										if (features[0] <= 129.7225) {
											return ( "rock");
										} else {
											if (features[0] <= 152.178) {
												return ( "metal");
											} else {
												return ( "disco");
											}
										}
									}
								} else {
									if (features[19] <= 55.15025) {
										if (features[0] <= 107.33455) {
											return ( "metal");
										} else {
											return ( "reggae");
										}
									} else {
										if (features[5] <= 611.457) {
											return ( "disco");
										} else {
											return ( "country");
										}
									}
								}
							} else {
								if (features[405] <= 22.3067) {
									if (features[3] <= 513.5065) {
										return ( "blues");
									} else {
										return ( "country");
									}
								} else {
									if (features[31] <= 135.6515) {
										if (features[469] <= 7.62035) {
											if (features[265] <= 251.05700000000002) {
												return ( "rock");
											} else {
												if (features[426] <= 43.147949999999994) {
													return ( "blues");
												} else {
													return ( "rock");
												}
											}
										} else {
											if (features[1] <= 743.4345000000001) {
												return ( "rock");
											} else {
												return ( "blues");
											}
										}
									} else {
										if (features[12] <= 392.884) {
											if (features[215] <= 4.19835) {
												return ( "rock");
											} else {
												if (features[47] <= 107.16050000000001) {
													return ( "disco");
												} else {
													return ( "metal");
												}
											}
										} else {
											if (features[0] <= 140.606) {
												return ( "blues");
											} else {
												return ( "country");
											}
										}
									}
								}
							}
						} else {
							if (features[5] <= 288.712) {
								if (features[256] <= 211.167) {
									if (features[102] <= 8.86449) {
										if (features[50] <= 20.99835) {
											if (features[0] <= 12.5064) {
												return ( "classical");
											} else {
												if (features[0] <= 25.420749999999998) {
													return ( "country");
												} else {
													return ( "hiphop");
												}
											}
										} else {
											return ( "reggae");
										}
									} else {
										if (features[56] <= 51.265) {
											return ( "jazz");
										} else {
											if (features[0] <= 55.1392) {
												return ( "country");
											} else {
												return ( "metal");
											}
										}
									}
								} else {
									return ( "reggae");
								}
							} else {
								if (features[30] <= 209.84699999999998) {
									if (features[280] <= 353.8225) {
										if (features[310] <= 75.2378) {
											if (features[291] <= 85.0503) {
												return ( "country");
											} else {
												if (features[315] <= 70.8142) {
													return ( "pop");
												} else {
													return ( "rock");
												}
											}
										} else {
											if (features[290] <= 82.95734999999999) {
												if (features[6] <= 363.85299999999995) {
													return ( "metal");
												} else {
													return ( "pop");
												}
											} else {
												if (features[374] <= 59.1622) {
													return ( "country");
												} else {
													return ( "disco");
												}
											}
										}
									} else {
										if (features[38] <= 76.2836) {
											return ( "reggae");
										} else {
											if (features[8] <= 531.1905) {
												return ( "disco");
											} else {
												if (features[0] <= 110.52669999999999) {
													return ( "pop");
												} else {
													return ( "rock");
												}
											}
										}
									}
								} else {
									if (features[35] <= 140.9625) {
										return ( "jazz");
									} else {
										if (features[11] <= 455.5475) {
											if (features[2] <= 1012.4415) {
												return ( "rock");
											} else {
												if (features[0] <= 87.1717) {
													return ( "reggae");
												} else {
													return ( "disco");
												}
											}
										} else {
											return ( "classical");
										}
									}
								}
							}
						}
					}
				} else {
					if (features[78] <= 31.82495) {
						if (features[481] <= 0.7474055) {
							return ( "hiphop");
						} else {
							if (features[6] <= 550.5184999999999) {
								if (features[2] <= 2143.675) {
									return ( "reggae");
								} else {
									return ( "blues");
								}
							} else {
								if (features[0] <= 226.57150000000001) {
									return ( "blues");
								} else {
									if (features[6] <= 692.5854999999999) {
										if (features[0] <= 299.6935) {
											return ( "reggae");
										} else {
											if (features[0] <= 417.30100000000004) {
												return ( "jazz");
											} else {
												return ( "country");
											}
										}
									} else {
										return ( "rock");
									}
								}
							}
						}
					} else {
						if (features[28] <= 155.3955) {
							if (features[217] <= 2.909065) {
								if (features[27] <= 108.9005) {
									return ( "blues");
								} else {
									return ( "metal");
								}
							} else {
								if (features[260] <= 639.8015) {
									if (features[466] <= 9.81567) {
										return ( "hiphop");
									} else {
										if (features[64] <= 49.65475) {
											if (features[0] <= 191.514) {
												return ( "jazz");
											} else {
												if (features[0] <= 302.8315) {
													return ( "disco");
												} else {
													return ( "hiphop");
												}
											}
										} else {
											if (features[25] <= 84.52584999999999) {
												if (features[0] <= 278.908) {
													return ( "disco");
												} else {
													return ( "hiphop");
												}
											} else {
												return ( "reggae");
											}
										}
									}
								} else {
									if (features[276] <= 121.47149999999999) {
										if (features[70] <= 42.8354) {
											if (features[0] <= 366.3565) {
												return ( "rock");
											} else {
												return ( "reggae");
											}
										} else {
											return ( "disco");
										}
									} else {
										if (features[20] <= 250.5005) {
											if (features[26] <= 199.70850000000002) {
												return ( "hiphop");
											} else {
												return ( "disco");
											}
										} else {
											if (features[0] <= 751.0835) {
												return ( "rock");
											} else {
												return ( "reggae");
											}
										}
									}
								}
							}
						} else {
							if (features[262] <= 415.326) {
								return ( "disco");
							} else {
								if (features[257] <= 1259.04) {
									if (features[304] <= 258.8335) {
										if (features[329] <= 116.955) {
											if (features[337] <= 89.49449999999999) {
												if (features[13] <= 344.203) {
													return ( "reggae");
												} else {
													return ( "rock");
												}
											} else {
												return ( "country");
											}
										} else {
											return ( "disco");
										}
									} else {
										return ( "blues");
									}
								} else {
									if (features[24] <= 206.5285) {
										return ( "hiphop");
									} else {
										if (features[0] <= 549.0675) {
											return ( "disco");
										} else {
											return ( "pop");
										}
									}
								}
							}
						}
					}
				}
			} else {
				if (features[234] <= 11.13795) {
					if (features[312] <= 253.938) {
						if (features[257] <= 292.95950000000005) {
							return ( "rock");
						} else {
							if (features[295] <= 169.685) {
								if (features[73] <= 101.2927) {
									if (features[0] <= 197.2355) {
										return ( "reggae");
									} else {
										return ( "country");
									}
								} else {
									if (features[0] <= 998.8054999999999) {
										return ( "metal");
									} else {
										return ( "disco");
									}
								}
							} else {
								if (features[63] <= 216.24099999999999) {
									if (features[381] <= 50.167249999999996) {
										return ( "rock");
									} else {
										if (features[256] <= 408.42150000000004) {
											if (features[2] <= 1448.56) {
												return ( "disco");
											} else {
												if (features[0] <= 141.27445) {
													return ( "reggae");
												} else {
													return ( "blues");
												}
											}
										} else {
											if (features[16] <= 204.7065) {
												return ( "reggae");
											} else {
												return ( "hiphop");
											}
										}
									}
								} else {
									if (features[149] <= 59.79575) {
										if (features[0] <= 256.7975) {
											return ( "rock");
										} else {
											return ( "hiphop");
										}
									} else {
										return ( "metal");
									}
								}
							}
						}
					} else {
						if (features[3] <= 1736.0900000000001) {
							if (features[0] <= 138.5195) {
								return ( "rock");
							} else {
								return ( "blues");
							}
						} else {
							return ( "metal");
						}
					}
				} else {
					if (features[2] <= 2124.765) {
						if (features[58] <= 132.35649999999998) {
							if (features[0] <= 77.6531) {
								return ( "jazz");
							} else {
								return ( "disco");
							}
						} else {
							if (features[85] <= 109.3825) {
								if (features[43] <= 165.0355) {
									if (features[0] <= 178.88150000000002) {
										return ( "rock");
									} else {
										return ( "reggae");
									}
								} else {
									return ( "pop");
								}
							} else {
								if (features[258] <= 1348.6350000000002) {
									if (features[13] <= 237.90750000000003) {
										if (features[0] <= 309.25350000000003) {
											return ( "metal");
										} else {
											return ( "hiphop");
										}
									} else {
										return ( "rock");
									}
								} else {
									if (features[11] <= 385.776) {
										return ( "disco");
									} else {
										if (features[0] <= 704.406) {
											if (features[0] <= 290.009) {
												return ( "pop");
											} else {
												if (features[0] <= 491.31550000000004) {
													return ( "country");
												} else {
													return ( "rock");
												}
											}
										} else {
											return ( "hiphop");
										}
									}
								}
							}
						}
					} else {
						if (features[260] <= 678.976) {
							return ( "country");
						} else {
							if (features[275] <= 551.761) {
								if (features[8] <= 547.2815) {
									return ( "hiphop");
								} else {
									return ( "disco");
								}
							} else {
								if (features[0] <= 644.9010000000001) {
									return ( "jazz");
								} else {
									return ( "pop");
								}
							}
						}
					}
				}
			}
		} else {
			if (features[191] <= 50.7928) {
				if (features[0] <= 662.067) {
					if (features[0] <= 483.58299999999997) {
						return ( "disco");
					} else {
						return ( "hiphop");
					}
				} else {
					return ( "reggae");
				}
			} else {
				if (features[36] <= 471.0085) {
					if (features[0] <= 241.2825) {
						return ( "disco");
					} else {
						if (features[10] <= 816.6044999999999) {
							if (features[273] <= 212.91449999999998) {
								return ( "hiphop");
							} else {
								return ( "pop");
							}
						} else {
							return ( "hiphop");
						}
					}
				} else {
					if (features[0] <= 460.774) {
						return ( "rock");
					} else {
						return ( "reggae");
					}
				}
			}
		}
	}
}